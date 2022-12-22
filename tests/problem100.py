# b = 50000000000

def find_n(x):
    a, b = 1, -1
    c = -2 * (x * x) + 2 * x
    d = ((b * b) - (4 * a * c)) ** .5
    n = (-b + d) / (2 * a)
    return n

# n = find_n(b)
# while n != int(n) or n < 1000000000000:
#     b += 1
#     n = find_n(b)

# print(b, n, n > 1000000000000)
A = {}
def a(n):
    if n in A:
        return A[n]
    if n == 0:
        return 1
    if n == 1:
        return 3
    A[n] = 6 * a(n-1) - a(n-2) - 2
    return A[n]

def f(x):
    return 8*x**2 - 8*x + 1

x = 1
n = 0
while n < 1000000000000:
    d = a(x)
    n = find_n(d)
    print(x, d, n, x / d)
    x += 1

print(d, n)