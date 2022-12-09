from time import sleep
from pprint import pprint

S = []
SQ = set()
for i in range(1, 1000):
    S.append(i ** 2)
    SQ.add(S[-1])

C = {}
for i in range(len(S)):
    j = i + 1
    while j < len(S):
        x = (S[j] + S[i]) // 2
        if x - S[i] == S[j] - x:
            if x not in C:
                C[x] = []
            y = x - S[i]
            C[x].append(y)
        
        j += 1


for x in C:
    if len(C[x]) > 1:
        for i in range(len(C[x])):
            y = C[x][i]
            for j in range(i+1, len(C[x])):
                z = C[x][j]
                if y + z in SQ and y - z in SQ:
                    print(x, y, z, x + y + z)