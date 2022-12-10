from pprint import pprint

P = {}

def is_prime(n):
    if n in P:
        return P[n]
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            P[n] = False
            return False
    P[n] = True
    return True

N = 10
C = {}

def choose(i, n, c):
    if i == N:
        if n not in C:
            C[n] = []
        C[n].append(c)
        return
    choose(i + 1, n, c + '0')
    choose(i + 1, n + 1, c + '1')

choose(0, 0, '')
digits = '0123456789'

G = {}
def generate(p, n, i, s):
    if p[0] == '1' and n == '0':
        return 0
    if i == len(p):
        num = int(s)
        if is_prime(num):
            return num
        return 0
    numbers = 0
    if p[i] == '0':
        for d in digits:
            if i == 0 and d == '0':
                continue
            numbers += generate(p, n, i + 1, s + d)
    else:
        numbers += generate(p, n, i + 1, s + n)
    return numbers

total = 0
for i in range(0, 10):
    primes = 0
    for c in range(0, len(C)):
        if primes > 0:
            break
        print(len(C) - c - 1)
        for p in C[len(C) - c - 1]:
            primes += generate(p, str(i), 0, '')
    print(i, primes)
    total += primes
print(total)
