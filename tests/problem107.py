from queue import PriorityQueue
from collections import defaultdict

# network = """\tA	B	C	D	E	F	G
# A	-	16	12	21	-	-	-
# B	16	-	-	17	20	-	-
# C	12	-	-	28	-	31	-
# D	21	17	28	-	18	19	23
# E	-	20	-	18	-	-	11
# F	-	-	31	19	-	-	27
# G	-	-	-	23	11	27	-"""



network = None
with open('../misc/p107_network.txt', 'r') as file:
    network = file.read()

lines = network.split('\n')[:-1]

V = len(lines[0].split(','))
G = defaultdict(list)

def add_edge(v1, v2):
    G[v1].append(v2)
    G[v2].append(v1)

def remove_edge(v1, v2):
    G[v1].pop()
    G[v2].pop()

M = []
for i in range(len(lines)):
    row = []
    for e in lines[i].split(','):
        if e != '-':
            row.append(int(e))
        else:
            row.append(0)
    M.append(row)


total = 0
queue = PriorityQueue()
for i in range(len(M)):
    for j in range(len(M[i])):
        weight = M[i][j]
        if weight:
            queue.put((weight, i, j))
            total += weight



def find_cycle(i, p, visited):
    visited[i] = True
    for n in G[i]:
        if not visited[n]:
            if find_cycle(n, i, visited):
                return True
        elif p != n:
            return True
    return False


def has_cycle():
    visited = [False] * V
    for i in range(V):
        if not visited[i]:
            if find_cycle(i, -1, visited):
                return True
    return False


cost = 0
while not queue.empty():
    e, v1, v2 = queue.get()
    add_edge(v1, v2)
    if has_cycle():
        remove_edge(v1, v2)
    else:
        cost += e

print(cost)

print((total // 2) - cost)
    
