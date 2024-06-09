from collections import defaultdict
import numpy as np
from random import randint


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


def s(x, C):
    return x


def get_equation(x, y, C):

    S = d(x, y, C)

    T = defaultdict(int)  # squared
    Q = defaultdict(int)  # original

    T[S] += 9

    for a in [l, r, s]:
        for b in [l, r, s]:
            T[d(a(x, C), b(y, C), C)] -= 1
            Q[d(a(x, C), b(y, C), C)] -= 2

    EQ, OR = [], []
    for ds in T:
        if ds == 0:
            continue
        EQ.append((T[ds], ds))
        OR.append((T[ds], ds + C // 2))

    for ds in Q:
        if ds == 0:
            continue
        EQ.append((Q[ds], ds + C // 2))

    return EQ, OR


def get_walk_times(C):

    EQS, seen = [], set()
    for i in range(C):
        for j in range(i + 1, C):
            D = d(i, j, C)
            if D in seen:
                continue
            seen.add(D)
            EQS.append(get_equation(i, j, C))

    R = (C // 2) * 2
    matrix = np.zeros((R, R))

    for i, e in enumerate(EQS):
        for n in range(0, 2):
            for (c, p) in e[n]:
                if p == 0:
                    continue
                matrix[i + n * (C // 2)][p - 1] = c

    ans = np.linalg.solve(matrix, np.ones(R))
    return ans * 9


def get_expected_time(C):

    ans = 0
    for c in range(2, C + 1):
        walk_times = get_walk_times(c)
        EV = 0
        for x in range(c):
            for y in range(c):
                if d(x, y, c) == 0:
                    continue
                EV += walk_times[d(x, y, c) - 1]

        ans += EV / (c * c)
    return ans

print('Problem 683 Solution:', get_expected_time(50))
