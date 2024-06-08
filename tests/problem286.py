
from functools import cache


@cache
def probability_making(i, k, N, q):

    if k < 0:
        return 0
    if i == N:
        if k == 0:
            return 1
        return 0

    prob = ((i+1) / q) * probability_making(i+1, k, N, q) + (1 - (i+1) / q) * probability_making(i+1, k-1, N, q)
    return prob

def search(tol=1e-17, T=.02, N=50, M=20):
    l, r = N, 2 * N

    p = 1
    lp = -1
    while abs(p - T) > tol:
        m = (l + r) / 2
        p = probability_making(0, M, N, m)
        if lp == p:
            break
        if p > T:
            l = m
        else:
            r = m
        
        lp = p 
        
    return l


p = search(T=.025, M=22)
print(round(p, 10)) 

