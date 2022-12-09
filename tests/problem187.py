def sieve(N):
    isprime = [True] * N
    prime = []
    SPF = [None] * N

    isprime[0] = isprime[1] = False
    for i in range(2, N):
        if isprime[i]:
            prime.append(i)
            SPF[i] = i
        j = 0
        while (j < len(prime) and
               i * prime[j] < N and
               prime[j] <= SPF[i]):
            isprime[i * prime[j]] = False
            SPF[i * prime[j]] = prime[j]
            j += 1
    return prime

def binary_search(a, x):
    l, h = 0, len(a) - 1
    while l <= h:
        m = (l + h) // 2
        if a[m] == x:
            return m
        elif a[m] < x:
            l = m + 1
        else:
            h = m - 1
    return l

N = int(10**8)
primes = sieve(int(10**4))
total = 0
for i in range(len(primes)):
    p = primes[i]
    j = binary_search(primes, N / p)
    if j - i < 0:
        break
    total += max((j - i), 0)
    
print(total)
