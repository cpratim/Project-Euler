M = {}

def solve(i, n, k):
    if i in M:
        return M[i]
    if i > n:
        return 0
    total = 0
    for j in range(i+k+1, n+1):
        total += solve(j, n, k) + 1
    M[i] = total
    return M[i]
    
total = 0
for k in [2, 3, 4]:
    total += solve(0, 50, k)
print(total)

