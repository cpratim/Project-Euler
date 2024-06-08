from functools import cache
from math import log2, ceil


@cache
def f(i, j, k, R=100):

  if i >= R:
    return 0
  if j >= R:
    return 1

  if k == 0:
    return .5 * f(i + 1, j, 1) + .5 * f(i, j, 1)

  max_win = -float('inf')
  for t in range(1, ceil(log2(R - j + 1)) + 2):
    max_win = max(
      max_win,
      (.5 ** t * f(i, j + 2 ** (t-1), 0) + (1 - .5 ** t) * .5 * f(i+1, j, 1)) / (.5 + .5 ** (t + 1))
    )
  # print(max_win)

    # (1 / 2 ** t * f(i, j + 2 ** (t-1), 0) + (1 - 1 / 2 ** t) * .5 * f(i+1, j, 1)) / (1 / 2 + 1 / 2 ** (t + 1))
  return max_win

print(f(0, 0, 0))
