from math import floor

def rings(n, t):
    a, b, c = 4, 4*n, -t
    x = (-b + (b**2 - 4*a*c)**0.5) / (2*a)
    return floor(x)

t = 1000000
s = 0
n = 1
r = rings(n, t)
while r > 0:
    s += r
    n += 1
    print(n, r)
    r = rings(n, t)

print(s)
