import math

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

primes = {}

def is_prime(n):
    if n in primes:
        return primes[n]
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            primes[n] = False
            return False
    primes[n] = True
    return True

def permutations(s, i, p, M, P):
    if i == len(s):
        P.append(p)
        return
    for j in range(len(s)):
        if not M[j]:
            M[j] = True
            permutations(s, i + 1, p + s[j], M, P)
            M[j] = False
    

a = '123456789'
M = [False] * len(a)
P = []
C = {}
products = set()
permutations(a, 0, '', M, P)

def n_sets(p, prod=1):
    
    if p == '':
        prods.add(prod)
        return 1
    total = 0
    for i in range(len(p)):
        n = int(p[:i+1])
        if is_prime(n):
            total += n_sets(p[i+1:], prod * n)
    return total

# def n_sets(p, ):
#     if len(p) == 0:
#         return {1,}
#     if p in C:
#         return C[p]
#     prods = set()
#     for i in range(len(p)):
#         n = int(p[:i+1])
#         if is_prime(n):
#             for s in n_sets(p[i+1:]):
#                 prods.add(n * s)
#     C[p] = prods
#     return prods

products = set()
for p in ['254789631']:
    products = products.union(n_sets(p))
print(len(products))
print(C)
# print(total)
