
def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

primes = []
n = 2
while len(primes) < 20:
    if is_prime(n):
        primes.append(n)
    n += 1

D = {}
def solve(i, p, l, M):
    if p in D:
        return D[p]
    if i == l:
        return 1
    total = 0
    for n in M:
        if M[n] == 0 or (n == 0 and i == 0):
            continue
        M[n] -= 1
        total += solve(i + 1, p * primes[n], l, M)
        M[n] += 1
    D[p] = total
    return total

M = {}
for i in range(10):
    M[i] = 3
print(solve(0, 1, 18, M))