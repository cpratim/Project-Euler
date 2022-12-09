
M = {}

def solve(i, n, l, a):
    if (i, l, a) in M:
        return M[(i, l, a)]

    if i == n:
        return 1
    
    total = solve(i+1, n, l, a=0)
    if a < 2:
        total += solve(i+1, n, l, a=a+1)
    if l < 1:
        total += solve(i+1, n, l=l+1, a=0)
    M[(i, l, a)] = total
    return total

print(solve(0, 30, 0, 0))