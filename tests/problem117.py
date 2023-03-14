
N = 50
DP = [0] * N

def solve(i):
    if i == N:
        return 1
    if i > N:
        return 0
    if DP[i] != 0:
        return DP[i]
    DP[i] = solve(i + 1) + solve(i + 2) + solve(i + 3) + solve(i + 4)
    return DP[i]

print(solve(0))
