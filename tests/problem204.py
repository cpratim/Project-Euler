from time import sleep

def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5)+1, 2):
        if n % i == 0:
            return False
    return True

P = []
for n in range(2, 100):
    if is_prime(n):
        P.append(n)

M = {}
visited = set()

def solve(n, limit, i):

    if n > limit:
        return 
    visited.add(n)
    
    for j in range(i, len(P)):
        p = P[j]
        if n * p > limit:
            break
        if n * p not in visited and n*p <= limit:
            solve(n * p, limit, j)
        
solve(1, int(1e9), 0)
print(len(visited))