M = {}

def solve(i, n, m):
    if (i, n) in M:
        return M[(i, n)]

    if n - i < m:
        return 1
    total = solve(i+1, n, m)
    for j in range(i+m+1, n+1):
        total += solve(j, n, m)
    M[(i, n)] = total + 1
    return M[(i, n)]
    
n = 50
s = solve(0, n, 50)
while s < 1000000:
    n += 1
    s = solve(0, n, 50)
    print(s)
print(n)