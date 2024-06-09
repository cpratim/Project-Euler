import numpy as np
from collections import defaultdict
from functools import cache

def default_matrix(d, t):
    if d == 1:
        return defaultdict(t)
    return defaultdict(lambda: default_matrix(d - 1, t))

@cache
def F(n):
    if n == 1:
        return 1
    if n == 2:
        return 1
    return F(n - 1) + F(n - 2)


def dist(i, j, active):
  i_idx = active.index(i)
  j_idx = active.index(j)
  if j > i:
    return j_idx - i_idx
  return len(active) - i_idx + j_idx 


def next(i, active, A):
    next_c = active[(i + 1) % len(active)]
    if next_c == A:
        next_c = active[(i + 2) % len(active)]
    return next_c


def f_W_T(T, M, W, D, P, C):

    active = [i for i in range(C) if M & (1 << i)]

    if len(active) == 1:
        return W

    if T not in active:
        for x in active:
            W[T][x][M] = 0
        return W

    matrix = np.eye(len(active))
    right = np.zeros(len(active))

    for idx, i in enumerate(active):
        max_prob, best_c, best_dist = 0, 0, float('inf')
        for j in active:
            if i == j:
                continue

            t_M = M & ~(1 << j)
            prob = W[i][next(idx, active, j)][t_M]
            c_dist = dist(i, j, active)
          
            if prob > max_prob:
                max_prob, best_c, best_dist = prob, j, c_dist
            if prob == max_prob and c_dist < best_dist:
                best_c, best_dist = j, c_dist

        if T == i:
            D[T][M] = best_c

        if best_c != T:
            right[idx] = P[i] * W[T][next(idx, active, best_c)][M & ~(1 << best_c)]

        matrix[idx][(idx + 1) % len(active)] = -(1 - P[i]) 

    prob = np.linalg.solve(matrix, right)
    for idx, i in enumerate(active):
        W[T][i][M] = prob[idx] 

    return W


def g_E(M, E, D, P, C):

    active = [i for i in range(C) if M & (1 << i)]
    if len(active) <= 1:
        return E

    matrix = np.eye(len(active))
    right = np.ones(len(active))

    for idx, i in enumerate(active):
        right[idx] += P[i] * E[next(idx, active, D[i][M])][M & ~(1 << D[i][M])]
        matrix[idx][(idx + 1) % len(active)] = -(1 - P[i])

    exp = np.linalg.solve(matrix, right)
    for idx, i in enumerate(active):
        E[i][M] = exp[idx]

    return E

def solve(C):
    P = [F(k) / F(C + 1) for k in range(1, C + 1)]

    W = default_matrix(3, float)
    E = default_matrix(2, float)
    D = default_matrix(2, float)

    for i in range(C):
        for j in range(C):
            W[i][j][1 << i] = 1

    for m in range(1, 1 << C):
        for i in range(C):
            W = f_W_T(i, m, W, D, P, C)

    for m in range(1, 1 << C):
        E = g_E(m, E, D, P, C)

    ans = E[0][(1 << C) - 1]   
    return f'{ans:.8f}'


if __name__ == '__main__':
    print('Problem 481 Solution: ', solve(C=14))
    