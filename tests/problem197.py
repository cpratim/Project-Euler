import math
def f(x):
    return math.floor(2**(30.403243784-x*x))*(1e-9)

def sequence(n):
    u_i = -1
    i = 0
    while i <= n:
        print(u_i)
        if i == n:
            # print(f"{i}: {u_i}")
            return u_i + f(u_i)
        u_i = f(u_i)
        i += 1

print(f"answer: {sequence(100000)}")

# 1.710637717