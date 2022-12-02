def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def is_prime(n):
    if n == 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5)+1, 2):
        if n % i == 0:
            return False
    return True

S = "PPPPNNPPPNPPNPN"

def P(n, i):
    prime = is_prime(n)
    if S[i] == "P":
        return 2 if prime else 1 
    return 1 if prime else 2
    
M = {}

def solve(i, n):
    if i == len(S):
        return .5
    if (i, n) in M:
        return M[(i, n)]
    p = P(n, i)
    if i == len(S) - 1:
        return p
    if n == 1:
        p *= 2 * solve(i+1, n+1)
    elif n == 500:
        p *= 2 * solve(i+1, n-1)
    else:
        p *= (solve(i+1, n-1) + solve(i+1, n+1))
    M[(i, n)] = p
    return M[(i, n)]

N, D = 0, (2 ** (len(S) - 1)) * (3 ** len(S)) * 500

for i in range(1, 501):
    N += solve(0, i)

g = gcd(N, D)
print(N // g, D // g)