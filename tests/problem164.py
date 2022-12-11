
M = {}

def solve(i, one, two, l):
    if i == l:
        return 1
    if (i, one, two) in M:
        return M[(i, one, two)]
    m = 10 - one - two
    total = 0
    for j in range(m):
        if i == 0 and j == 0:
            continue
        total += solve(i + 1, two, j, l)
    M[(i, one, two)] = total
    return total

l = 20
total = solve(0, 0, 0, l)
print(total)