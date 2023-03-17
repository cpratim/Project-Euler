from math import floor
from functools import lru_cache
from collections import defaultdict

def recurrance(i, j, d):
    if i == 0 or j == 0:
        return 0
    if DP[i][j][d] != -1:
        return DP[i][j][d]
    if d == 0:
        DP[i][j][d] = 1 + recurrance(i - 1, j, 0) + recurrance(i, j-1, 0) - recurrance(i-1, j-1, 0)
    if d == 1:
        DP[i][j][d] = .5 + recurrance(i-1, j, 3) 
    if d == 2:
        DP[i][j][d] = .5 + recurrance(i, j-1, 4)
    if d == 3:
        DP[i][j][d] = .5 + recurrance(i, j, 2)
    if d == 4:
        DP[i][j][d] = .5 + recurrance(i, j, 1)
    return DP[i][j][d]

@lru_cache(maxsize=None)
def get_sum(i, j):
    if i == 0 or j == 0:
        return 0
    
    total = recurrance(i, j, 0) + floor(recurrance(i, j, 1)) + floor(recurrance(i, j, 2))
    
    D = defaultdict(list)
    for k in range(i, 0, -1):
        for l in range(j, i-k, -1):
            D[k+l].append((k, l))

    for k in D:
        m = float('inf')
        for l, m in D[k]:
            m = min(m, min(floor(recurrance(l, m, 1)), floor(recurrance(l, m, 2))))
        total += m

    return total + get_sum(i-1, j) + get_sum(i, j-1) - get_sum(i-1, j-1)


if __name__ == "__main__":
    N, M = 47, 43

    DP = [[[-1 for _ in range(5)] for _ in range(M + 1)] for _ in range(N + 1)]

    total = 0
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            total += get_sum(i, j)

    print(total)