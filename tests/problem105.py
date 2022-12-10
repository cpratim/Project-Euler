from pprint import pprint

def generate_sums(s, i, n, r, S, F):
    
    if i == len(s):
        print(r, n)
        print(len(S))
        print()
        if r in S:
            return False
        S.add(r)
        if n not in F:
            F[n] = [float('inf'), -float('inf')]
        F[n][0] = min(F[n][0], r)
        F[n][1] = max(F[n][1], r)
        return True
    return generate_sums(s, i + 1, n, r, S, F) and generate_sums(s, i + 1, n + 1, r + s[i], S, F)

def check(s):
    S, F = set(), {}
    status = generate_sums(s, 0, 0, 0, S, F)
    if not status:
        return False
    for i in range(1, len(s) + 1):
        if F[i][0] <= F[i - 1][1]:
            return False
    return True

with open('../misc/p105_sets.txt') as f:
    sets = [list(map(int, line.split(','))) for line in f]

print(check([37,48,34,59,39,41,40]))
# total = 0
# for s in sets:
#     if check(s):
#         total += sum(s)
# print(total)

'''
0
0
0
0
4
3
3
7
2
2
2
6
5
5
9
1
1
1
1
5
0
'''