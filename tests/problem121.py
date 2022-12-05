from math import floor 

P = []
Q = []
A = 1
N = 15
for i in range(1, N+1):
    P.append(1 / (i+1))
    Q.append(1 - (1 / (i+1)))
    A *= P[-1]

M = {}

def choose(i, n, k, p):
    S = 0
    if k == 0:
        return p
    for j in range(i, n):
        p /= P[j]
        p *= Q[j]
        S += choose(j+1, n, k-1, p)
        p /= Q[j]
        p *= P[j]
    return S

def F(N, n):
    return choose(0, N, n, A)


total = 0
for i in range(N // 2 + 1 - int(N % 2 == 0)):
    print(i)
    total += F(N, i)

print(total)
print(floor(1 / total))
