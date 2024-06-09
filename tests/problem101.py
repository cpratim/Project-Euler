import numpy as np
from math import floor

# A = np.array([
#     [1, 1, 1],
#     [1, 2, 4],
#     [1, 3, 9]
# ])

# b = np.array([1, 8, 27])

# x = np.linalg.solve(A, b)
# s = 0
# print(x)
# for i in range(3):
#     s += x[i] * 4**(2-i)
# print(s)

def G(n):
    s = 0
    for i in range(11):
        s += (-1)**i * n**i
    return s

# def G(n):
#     return n ** 3

D = 10
R = []
for i in range(1, D+1):
    R.append(G(i))

t = 0
for i in range(1, D+1):
    x = []
    y = []
    for j in range(i):
        for k in range(i):
            x.append((j+1)**k)
        y.append(R[j])
    A = np.array(x).reshape(i, i)
    s = np.linalg.solve(A, y)
    for j in range(i):
        t += (i+1)**j * s[j]

print("Problem 101 Solution: ", floor(t))
