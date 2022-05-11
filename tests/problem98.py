from math import sqrt, floor, log10, ceil
from pprint import pprint
import json

words = []
with open('../misc/p098_words.txt', 'r') as f:
    for w in f.read().split(','):
        words.append(w[1:-1])

def gen_squares():
    n = 10000000
    M = {}
    while n > 0:
        s = n**2
        n_digits = ceil(log10(s))
        if n_digits not in M:
            M[n_digits] = set()
        M[n_digits].add(s)
        n -= 1
    return M

SQ = gen_squares()
print('generated')

def anagramic_map(word, n):
    m = {}
    y = {}
    for c in word[::-1]:
        d = n % 10
        if d in y:
            if y[d] != c:
                return False
        else:
            m[c] = d
            y[d] = c
        n = n // 10
    return m

def gen_int(word, m):
    n = 0
    i = 0
    for c in word[::-1]:
        if c not in m:
            return False
        n += m[c] * 10 ** i
        i += 1
    return n

def pattern(w):
    m = {}
    p = ""
    i = 0
    for c in w:
        if c not in m:
            m[c] = i
            i += 1
        p += str(m[c])
    return p

PM = {}
LM = {}
MP = {}
for w in words:
    l = len(w)
    if l not in LM:
        LM[l] = []
    LM[l].append(w)
    p = pattern(w)
    MP[w] = p
    if p not in PM:
        PM[p] = []
    PM[p].append(w)


with open('N.json', 'r') as f:
    N = json.load(f)

patterns = list(N.keys())

def solve():
    word_len = 14
    mx = 0
    while word_len > 1:
        for w1 in LM[word_len]:
            p = MP[w1]
            if p not in N:
                continue
            for w2 in LM[word_len]:
                if w1 != w2:
                    if sorted(w1) == sorted(w2):
                        for s in N[p]:
                            m = anagramic_map(w1, s)
                            c = gen_int(w2, m)
                            if c in SQ[word_len]:
                                if s > mx:
                                    mx = s
        word_len -= 1
    return mx


print(solve())
# S = set()
# for w in words:
#     S.add(pattern(w))
#
# N = {}
# n = 10000000 - 1
#
# while n != 0:
#     s = n**2
#     p = pattern(str(s))
#     if p in S:
#         if p not in N:
#             N[p] = []
#         N[p].append(s)
#     n -= 1
#
# with open('N.json', 'w') as f:
#     json.dump(N, f, indent=4)
#


