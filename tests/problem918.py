from functools import cache
from math import floor

@cache
def solve(n: int) -> int:
    if n == 0:
        return 4
    if n == 1:
        return 1
    
    r = floor(n / 2)
    if n % 2 == 0:
        return 2 * solve(r)
    return solve(r) - 3 * solve(r + 1)

print(solve(10))

def S(n: int) -> int:
    return 4 - solve(n // 2)


print(S(int(10 ** 12)))



