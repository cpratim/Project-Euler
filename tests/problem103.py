from pprint import pprint

S = set()

def subsets(n):
    sets = []
    for i in range(1, 1 << n):
        sets.append([j for j in range(n) if i & (1 << j)])
    return sets

# a = [20, 31, 38, 39, 40, 42, 45]
a = [11, 17, 20, 22, 23, 24]
A = sum(a)
n = len(a)
for s in subsets(n):
    ss = 0
    ssid = ''
    for i in s:
        ssid += str(i)
        ss += a[i]
    S.add((ss, len(s), ssid))

S.add((0, 0, ''))

def generate_d(r_min, r_max, i, n, s=0):
    if i == n:
        if s < 0:
            D.append(P[:])
        return
    for p in range(-r_min, r_max + 1):
        P.append(p)
        generate_d(r_min, r_max, i + 1, n, s + p)
        P.pop()


def check(d):
    t = []
    seen = set()
    for ss, l, ssid in S:
        for c in ssid:
            ss += d[int(c)]
        if ss in seen:
            return False
        seen.add(ss)
        t.append((l, ss))
    t.sort()
    m = 0
    ll = 0
    for l, ss in t:
        if l > ll and ss <= m:
            return False
        m = max(m, ss)
        ll = l
    return True

r_min = 4
r_max = 4
P = []
D = []
MIN = A
MIN_SET = None
generate_d(r_min, r_max, 0, n)
print(len(D))
for d in D:
    s = A + sum(d)
    if check(d):
        if s < MIN:
            MIN = s
            MIN_SET = d
            print(MIN, MIN_SET)

print(MIN)
print(MIN_SET)

print(MIN)
for i in range(len(MIN_SET)):
    a[i] += MIN_SET[i]
STRING = ''
for i in a:
    STRING += str(i)
print(STRING)

