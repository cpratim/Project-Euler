
T = 10**10
use = []

i = 0
while T >= 2 ** i:
    use.append(2 ** i)
    i += 1

print(use)

cache = {}
def solve(i, t):
    if (i, t) in cache:
        return cache[(i, t)]
    if t < 0:
        return 0
    if i == len(use):
        if t == 0:
            return 1
        return 0
    ans = solve(i + 1, t) + solve(i + 1, t - use[i]) + solve(i + 1, t - 2 * use[i])
    cache[(i, t)] = ans
    return ans



print(solve(0, T))

# print(cache)
