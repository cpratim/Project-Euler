import math
from pprint import pprint
from time import sleep

def get_primes(N):
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


primes = get_primes(1000000)
P = set(primes)


def get_divisors(n):
    div = set()
    for i in range(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            div.add(n // i)
            div.add(i)
    return div


def smallest_prime_factor(n):
    i = 0
    while n % primes[i] != 0:
        i += 1
    return primes[i]


F = {}
C = {}


def get_proper_factors(n):
    if n in F:
        return F[n]
    if n == 1 or n in P:
        F[n] = {1, n}
    else:
        pf = smallest_prime_factor(n)
        F[n] = set()
        div = n // pf
        if div in F:
            for f in F[div]:
                F[n].add(f)
                F[n].add(f * pf)
        else:
            F[n] = get_divisors(n)
    return F[n]


def find_chain(n):
    c = set()
    ch = []
    if n == 1:
        C[n] = None
        return
    if n in C:
        return
    while n not in c:
        if n in P or n == 1 or n > 1000000:
            C[n] = None
            for i in c:
                C[i] = None
            return
        c.add(n)
        ch.append(n)
        n = sum(get_proper_factors(n)) - n
    ce = set(ch[ch.index(n):])
    for i in c:
        if i in ce:
            C[i] = len(ce)
        else:
            C[i] = None

longest = 0
small = 0
N = 1000000
for n in range(1, N):
    find_chain(n)
    if C[n]:
        if C[n] > longest:
            longest = C[n]
            small = n
        if C[n] == longest:
            if n < small:
                small = n

print(small)