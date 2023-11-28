import numpy as np
import sys
from random import shuffle
from scipy.optimize import minimize, differential_evolution
import matplotlib.pyplot as plt

sys.setrecursionlimit(10000)

N = 1000
T = 1_000_000_000

def f(j, p, log=False):
    v = 1
    for _ in range(j):
        v *= (1 + 2 * p)
    if v < T:
        return 0
    for _ in range(N - j):
        v *= (1 - p)
    if log:
        print(j, v)
    if v >= T:
        return 1
    return 0

def find_j(p):
    l, r = 0, N
    ans = N
    while l <= r:
        m = (l + r) // 2
        if f(m, p):
            ans = min(ans, m)
            r = m - 1
        else:
            l = m + 1
    return ans

def f_exp(p):
    n = 9 * np.log(10) - 1000 * np.log(1 - p)
    d = np.log(1 + 2 * p) - np.log(1 - p)
    return n / d


# p = .5
# j = find_j(p)
# print(j)
# print(f(j, p, True))
# print(f_exp(p))
# x = np.linspace(0, 1, 1000)
# y = [f_exp(p) for p in x]
# plt.plot(x, y)
# plt.show()

# res = differential_evolution(
#     lambda x: f_exp(x), 
#     bounds = [(0, 1)], 
#     tol=1e-20,
#     maxiter=100000,
# )
# print(res)
# print(res.x[0])

x = 0.146883922440941
print(find_j(x))


print(f_exp(x))
a = "0.9999928361867135946707021260049969782148510846511089573140458521"


print(a[:2 + 12])