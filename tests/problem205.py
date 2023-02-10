from functools import reduce
from pprint import pprint
from collections import defaultdict

F = {}

def factorial(n):
    if n == 0:
        return 1
    if n in F:
        return F[n]
    F[n] = n * factorial(n - 1)
    return F[n]

def multinomial_coefficient(n, k):
    
    f = factorial(n)
    for i in k:
        f /= factorial(i)
    return f

def generate_rolls(i, n, sides, last, roll, base, S):
    if i == n:
        k = list(roll.values())
        s = sum([i * roll[i] for i in roll])
        S[s] += (multinomial_coefficient(n, k) * base)
        return
    for j in range(last, sides+1):
        roll[j] += 1
        generate_rolls(i+1, n, sides, j, roll, base, S)
        roll[j] -= 1


if __name__ == '__main__':
    pn, ps = 9, 4
    cn, cs = 6, 6
    P, C = defaultdict(int), defaultdict(int)
    generate_rolls(0, pn, ps, 1, defaultdict(int), 1.0 / ps**pn, P)
    generate_rolls(0, cn, cs, 1, defaultdict(int), 1.0 / cs**cn, C)
    P = sorted(P.items())
    C = sorted(C.items())
    win = 0
    for i in range(len(P)):
        for j in range(len(C)):
            if P[i][0] > C[j][0]:
                win += P[i][1] * C[j][1]
    print(win)
