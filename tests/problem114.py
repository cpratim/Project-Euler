M = {}

def solve(i, n):
    if i in M:
        return M[i]

    if n - i < 3:
        return 1
    total = solve(i+1, n)
    for j in range(i+4, n+1):
        total += solve(j, n)
    M[i] = total + 1
    return M[i]
    
print(solve(0, 50))