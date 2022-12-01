# from time import sleep
# from pprint import pprint



# count = [0]

def increasing(i, l, m, M, p):
    if i == l - 1:
        return 1
    if (i, m) in M:
        return M[(i, m)]
    s = 0
    if m is None:
        for j in range(10):
            s += increasing(i, l, j, M, str(j) + p)
    else:
        
        for n in range(m+1):
            s += increasing(i+1, l, n, M, str(n) + p)
    M[(i, m)] = s
    return s


def decreasing(i, l, m, M):
    if i == l - 1:
        return 1
    
    if (i, m) in M:
        return M[(i, m)]
    s = 0
    if m is None:
        s += decreasing(i+1, l, None, M)
        for j in range(10):
            s += decreasing(i, l, j, M)
        
    else:
        for n in range(m+1):
            s += decreasing(i+1, l, n, M)
    M[(i, m)] = s
    return s

I, D = {}, {}
print(decreasing(0, 100, None, D) + increasing(0, 100, None, I, '') - 10*99 - 2)



