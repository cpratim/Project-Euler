from collections import defaultdict


DP = defaultdict(dict)

FULL = 1023
MAX_LEN = 40

def solve(i, l, mask):
    if i == MAX_LEN - 1:
        return int(mask == FULL)
    if l in DP[i] and mask in DP[i][l]:
        return DP[i][l][mask]
    if l not in DP[i]:
        DP[i][l] = {}
    res = 0
    if l < 9:
        res += solve(i+1, l+1, mask | (1 << (l+1)))
    if l > 0:
        res += solve(i+1, l-1, mask | (1 << (l-1)))
    
    DP[i][l][mask] = res
    return res



if __name__ == '__main__':
    res = 0
    for i in range(1, 10):
        for j in range(0, MAX_LEN):
        
            res += solve(j, i, 1 << i)
    print(res)
        

# mask = 0
# for i in range(10):
#     if i == 3 or i == 5 or i == 7: continue;
#     mask = mask | (1 << i)

# mask2 = 0
# mask2 = mask2 | (1 << 3)
# mask2 = mask2 | (1 << 5)
# mask2 = mask2 | (1 << 7)


# print(mask | mask2)