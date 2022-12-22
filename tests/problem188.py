m = 1e8
import sys
sys.setrecursionlimit(5000)

def base2(n):
    a = []
    i = 0
    while n > 0:
        a.append((n % 2)*(2**i))
        i += 1
        n //= 2
    return a

# print(base2(117))

M = dict()

def modpow(a, b, m):
    # print(a, b)
    ret = 1
    if b in M:
        return M[b]
    for i in range(int(b)):
        ret = ret * a % m
    M[b] = ret
    # print(a, b)
    return ret

def f(a, b):
    if b == 1:
        return a
    exp = f(a, b - 1)
    p = 1
    for power in base2(exp):
        if power == 0:
            continue
        p *= modpow(a, power, m)
        p %= m
    return p



# def f(a, b):
#     k = 1
#     while k < b:
#         a = (a ** ) % m

# print(f(3, 3))
print(f(1777, 1855))