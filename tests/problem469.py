
import sys

sys.setrecursionlimit(10000)
# def solve(n):
#     if n in M:
#         return M[n]
#     if n == 0:
#         return 0
#     if n == 1:
#         return 1
#     if n == 2:
#         return (1 / 2)

#     if n == 3:
#         return (1 / 3)
    
#     d1, d2 = n - 2, n - 3
#     h1 = d2 // 2 + int(d2 % 2 == 1)
#     h2 = d2 // 2
#     r = (h1 / d2) * ((solve(d1) * d1 + 1) / n)
#     if d2 > 1:
#         r += (h2 / d2) * ((solve(d2) * d2 + 1) / n)
#     M[n] = r
#     return r

M = {}

def solve(n):
    if n in M:
        return M[n]
    if n == 2:
        return 1
    if n == 3:
        return 1
    t = 0
    for i in range(2, n-1):
        t += (solve(i)) + (solve(n-i))
    t = t / (n - 3)
    M[n] = t
    return t

N = 6
print(1 - (solve(N) / N))
