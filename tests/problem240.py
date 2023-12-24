from math import comb
from functools import lru_cache

def C(n, k):
    return comb(n, k)

F = [1]
for i in range(1, 21):
    F.append(F[-1] * i)

def stars_and_bars_with_constraints(n, k, m):
    def basic_stars_and_bars(n, k):
        return comb(n + k - 1, k - 1)

    def count_configurations(n, k, m):
        count = 0
        for i in range(k + 1):
            if n - i * (m + 1) < 0:
                break
            sign = (-1) ** i
            count += sign * comb(k, i) * basic_stars_and_bars(n - i * (m + 1), k)
        return count

    if n > k * m:
        return 0
    return count_configurations(n, k, m)


def solve_layer(
        n_dice, n_top, target, 
        max_top, n_max_top, min_top, n_min_top, n_min_bot
    ):
    target -= n_max_top * max_top + n_min_top * min_top + (n_top - n_max_top - n_min_top) * (min_top + 1)

    # print(target)
    # print(target)
    free_spots = n_top - n_max_top - n_min_top
    if max_top == min_top + 1 and target != 0:
        return 0
    if target < 0 or (target > 0 and free_spots == 0):
        return 0

    if target == 0:
        r_combos = 1
    else:
        r_combos = stars_and_bars_with_constraints(target, free_spots, (max_top - min_top - 2))
        if r_combos == 0:
            return 0
    
    free_dice = n_dice - n_top - n_min_bot
    
    R = C(n_dice, n_top) * C(n_top, n_max_top) * r_combos * C(n_dice - n_top, n_min_bot + n_min_top) * (min_top - 1) ** (free_dice)
    return R

def solve_static_layer(n_dice, n_top, value, target):
    if value * n_top != target:
        return 0
    total = 0
    for n_max_top in range(n_top, n_dice + 1):
        total += C(n_dice, n_max_top) * (value - 1) ** (n_dice - n_max_top)
    return total


def solve(n_dice, n_sides, n_top, target):

    total = 0
    for max_top in range(1, n_sides + 1):
        for min_top in range(1, max_top):
            for n_max_top in range(1, n_top):
                # print(n_max_top)
                
                for n_min_top in range(1, n_top - n_max_top + 1):
                    for n_min_bot in range(0, n_dice - n_top + 1):
                        
                        R = solve_layer(n_dice, n_top, target, max_top, n_max_top, min_top, n_min_top, n_min_bot)
                        # if R != 0:
                        #     print(max_top, min_top, n_max_top, n_min_top, n_min_bot, R)
                        total += R
    for max_top in range(1, n_sides + 1):
        r = solve_static_layer(n_dice, n_top, max_top, target)
        total += r
        # total += solve_static_layer(n_dice, n_top, max_top, target)

    return total

def permutations_array(dices):
    fac = F[len(dices)]
    counts = {}
    for d in dices:
        if d not in counts:
            counts[d] = 0
        counts[d] += 1
    
    for k in counts:
        fac //= F[counts[k]]
    return fac


dices = []
def solve(n_dice, n_top, target, max_dice):
    if len(dices) == n_top and sum(dices) != target:
        return 0
    if len(dices) == n_dice:
        return permutations_array(dices)
    total = 0
    for i in range(1, max_dice + 1):
        dices.append(i)
        total += solve(n_dice, n_top, target, i)
        dices.pop()
    return total

    



if __name__ == '__main__':
    n_dice = 20
    n_sides = 12
    n_top = 10
    target = 70
    print(solve(n_dice, n_top, target, n_sides))
    
    # print(solve(n_dice, n_sides, n_top, target))
    # print(stars_and_bars_with_constraints(70, 10, 12))
    # print(solve_layer(5, 3, 15, 6, 2, 3, 1, 0))
    # print(stars_and_bars_with_constraints(3, 1, 3 - 1))
    # print(solve_layer(5, 3, 15, 6, 1, 3, 1, 0))