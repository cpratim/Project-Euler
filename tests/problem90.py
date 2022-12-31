from pprint import pprint
from itertools import combinations

D = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
squares = ['01', '04', '09', '16', '25', '36', '49', '64', '81']

cube = set()
cubes = []
def get_all_cubes(i, n, D):
    if n == 0: 
        
        cubes.append(set([_ for _ in cube]))
        return
    for j in range(i, len(D)):
        cube.add(D[j])
        get_all_cubes(j+1, n-1, D)
        cube.remove(D[j])

get_all_cubes(0, 6, D)
pprint(cubes)

def valid(c1, c2):
    if 6 in c1: c1.add(9)
    if 9 in c1: c1.add(6)
    if 6 in c2: c2.add(9)
    if 9 in c2: c2.add(6)

    for s in squares:
        d1, d2 = int(s[0]), int(s[1])
        if (d1 in c1 and d2 in c2) or (d2 in c1 and d1 in c2):
            continue
        else:
            return False
    return True


num_valid = 0
for i in range(len(cubes)):
    for j in range(i+1, len(cubes)):
        if valid(cubes[i], cubes[j]):
            num_valid += 1

print(num_valid)