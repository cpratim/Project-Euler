import matplotlib.pyplot as plt
from queue import PriorityQueue, deque

def is_prime(n):
    if n == 1:
        return False

    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False

    return True

def n_factors(n):
    count = 0
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            print(i, n // i)
            count += 2
    return count

def gen(n):
    x = n + 1
    Y = set()
    s = 0
    while x not in Y:
        num, dem = (x * n), (x - n)
        if num % dem == 0:
            # s.append((x, num // dem))
            Y.add(num // dem)
            s += 1
        x += 1
    return s


    
P = []
for i in range(2, 17):
    if is_prime(i):
        P.append(i)

T = 1000
queue = PriorityQueue()
visited = set()
M = 200000

queue = deque()
for i in P:
    queue.append((i, gen(i)))

while queue:
    n, lg = queue.popleft()
    if n < M and n not in visited:
        visited.add(n)
        g = gen(n)
        
        if g > T:
            print(n, g)
            break
        if g >= lg:
            for p in P:
                queue.append((n * p, g))

# for i in range(0, len(P)):
#     g = gen(P[i])
#     d = abs(g - T)
#     queue.put((P[i], P[i], g, i))
#     visited.add(P[i])


# while not queue.empty():
#     d, n, g, i = queue.get()
#     print(n, g, d, i)
#     if g >= T:
#         print(i, g)
#         break
#     for j in range(i, len(P)):
#         nn = n * P[j]
#         if nn not in visited:
#             ng = gen(nn)
#             nd = abs(ng - T)
#             queue.put((nn, nn, ng, j))
