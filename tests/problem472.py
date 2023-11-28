import numpy as np

def furthest(a):
    d, j = -1, -1
    for i in range(len(a)):
        if a[i] != 0:
            continue
        lc, rc = i, i
        while lc >= 0 and a[lc] == 0:
            lc -= 1
        while rc < len(a) and a[rc] == 0:
            rc += 1
        if lc < 0:
            lc = float('-inf')
        if rc >= len(a):
            rc = float('inf')
        c = min(i - lc, rc - i)
        if c > d and c > 1:
            d, j = c, i
    return j

def sim(i, x):
    x[i] = 1
    j = 2
    while furthest(x) != -1:
        x[furthest(x)] = j
        j += 1
    return x

def f(n):
    
    r = []
    for i in range(n):
        x = np.zeros(n)
        print(i, sim(i, x))
        r.append(sim(i, x))
    r = np.array(r)

    # return np.sum(r == r.max()), int(r.max())


f(7)
# for i in range(1, 100):
#     print(i, f(i))