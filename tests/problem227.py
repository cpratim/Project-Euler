from collections import defaultdict
import numpy as np

def d(x, y, C):
    return min(abs(x - y), C - abs(x - y))

def l(x, C):
    if x - 1 < 0:
        return C - 1  
    return x - 1

def r(x, C):
    if x + 1 > C - 1:
        return 0
    return x + 1

def get_equation(x, y, C):

    S = d(x, y, C)

    T = defaultdict(int)

    T[S] += 36

    T[d(l(x, C), l(y, C), C)] -= 1
    T[d(l(x, C), r(y, C), C)] -= 1
    T[d(l(x, C), y, C)] -= 4

    T[d(r(x, C), l(y, C), C)] -= 1
    T[d(r(x, C), r(y, C), C)] -= 1
    T[d(r(x, C), y, C)] -= 4

    T[d(x, l(y, C), C)] -= 4
    T[d(x, r(y, C), C)] -= 4
    T[d(x, y, C)] -= 16

    EQ = []
    for ds in T:
        EQ.append((T[ds], ds))

    EQ.sort()
    EQ = ','.join([f'{x[0]}|{x[1]}' for x in EQ])    
    return EQ

def get_walk_times(C):

    EQS = set()
    seen = set()
    for i in range(C):
        for j in range(i+1, C):
            D = d(i, j, C)
            if D in seen:
                continue
            seen.add(D)
            EQS.add(get_equation(i, j, C))

    R = C // 2
    matrix = np.zeros((R, R))
    for i, e in enumerate(EQS):
        for g in e.split(','):
            c, p = [int(x) for x in g.split('|')]
            if p == 0:
                continue
            matrix[i][p-1] = c
    
    ans = np.matmul(np.linalg.inv(matrix), np.ones(R))
    return ans * 36

def get_expected_time(C):

    walk_times = get_walk_times(C)
    return walk_times[C // 2 - 1]
  
print("Problem 227 Solution:", get_expected_time(100))