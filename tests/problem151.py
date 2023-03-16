from pprint import pprint
from collections import defaultdict
from time import sleep

D = defaultdict(float)

P = {
    1: 1,
    2: 0,
    3: 0,
    4: 0,
    5: 0,
}

def cut(s):
    P[s] -= 1
    for i in range(s+1, 6):
        P[i] += 1

def cut_back(s):
    P[s] += 1
    for i in range(s+1, 6):
        P[i] -= 1

def backtrack(i, n, p, e):
    if i == n:
        D[e] += p
        return

    t = sum(P.values())
    
    for s in range(1, 6):
        if P[s] == 0:
            continue
        num = P[s]
        cut(s)
        backtrack(i+1, n, p * (num / t), e + int(t == 1))
        cut_back(s)

if __name__ == '__main__':
    backtrack(0, 15, 1, 0)
    t = 0
    for k, v in D.items():
        t += k * v
    print(t - 1)

