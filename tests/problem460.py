from heapq import *
from math import log, e
import matplotlib.pyplot as plt
import numpy as np
from sortedcontainers import SortedList
from collections import deque


def calc_time(x, y, n_x, n_y):
    dist = ((n_x - x)**2 + (n_y - y)**2) ** 0.5
    if n_y == y:
        return dist / y
    return dist / ((n_y - y) / (log(n_y) - log(y)))
    

seen = set()

def find_shortest(d):

    queue = [(0, 0, 1, -1, -1)]
    backtrack = {}

    while queue:

        t, x, y, px, py = heappop(queue)
        if (x, y) in seen:
            continue

        backtrack[(x, y)] = (px, py)
        if x == d and y == 1:
            return t, backtrack

        seen.add((x, y))

        for n_x in range(x, min(d+1, x + 20)):
            if n_x < (d // 2):
                for n_y in range(y, min(d // 2 + 1, y + 20)):
                    if n_x == x and n_y == y:
                        continue
                    if (n_x, n_y) in seen:
                        continue
                    d_t = calc_time(x, y, n_x, n_y)
                    heappush(queue, (t + d_t, n_x, n_y, x, y))
            else:
                for n_y in range(max(1, y - 20), y+1):
                    if n_x == x and n_y == y:
                        continue
                    if (n_x, n_y) in seen:
                        continue
                    d_t = calc_time(x, y, n_x, n_y)
                    heappush(queue, (t + d_t, n_x, n_y, x, y))

    return None


T_MAX = 18.421041470543468

def find_shortest_space(space, d):
    queue = [(0, 0, 1)]
    seen = set()
    while queue:
        t, x, y = heappop(queue)
        # print(len(seen))
        if (x, y) in seen:
            continue
        
        if x == d // 2 and y == d // 2:
            return t

        # if len(seen) % 1000 == 0:
        #     print(len(seen))

        seen.add((x, y))
        space.remove((x, y))
        i = space.bisect_left((x, 0))
        

        while i < len(space) and space[i][0] < (x + 500):
            n_x, n_y = space[i]
            i += 1
            if n_x < x or (n_x == x and n_y == y):
                continue
            if (n_x, n_y) in seen:
                continue

            if n_x < (d // 2) and n_y < y:
                continue

            if n_x > (d // 2) and n_y > y:
                continue
            
            # if abs(n_y - y) > 100:
            #     continue

            d_t = calc_time(x, y, n_x, n_y)
            heappush(queue, (t + d_t, n_x, n_y))
            
    return 0


def generate_search_space(d, f, r=2):
    space = set()
    for x in range(d // 2 + 1):
        fp = round(f(x / d) * d)
        # print(x, fp)
        for dx in range(x-r, x+r+1):
            for dy in range(fp-r, fp+r+1):
                if dx < 0 or dy < 1 or dx > d or dy > d:
                    continue
                space.add((dx, dy))
    for x in range(0, 50):
        for y in range(x+1, x+100):
            space.add((x, y))
    space.add((0, 1))
    # space.add((d, 1))
    space_sor = SortedList(space)
    return space_sor


def generate_seach_space_bfs(x, y, d, max_size=1000, d_t=3):
    for i in range(len(x)):
        x[i] = round(x[i] * d)
        y[i] = round(y[i] * d)

    queue = deque([(i, j) for i, j in zip(x, y)])
    space = set()

    dirs = [(d_t, 0), (0, d_t), (-d_t, 0), (0, -d_t), (d_t, d_t), (-d_t, d_t), (d_t, -d_t), (-d_t, -d_t)]
    while queue and len(space) < max_size:
        x, y = queue.popleft()

        if (x, y) in space or x > d // 2 or y > d // 2 or x < 0 or y < 1:
            continue

        space.add((x, y))
        for dx, dy in dirs:
            queue.append((x + dx, y + dy))

    space.add((0, 1))
    space.add((d // 2, d // 2))
    space_sor = SortedList(space)

    return space_sor




if __name__ == '__main__':
    d = 4
    # t, backtrack = find_shortest(d)
    # print(t)
    # end = (d, 1)
    # path = []
    # while end != (-1, -1):
    #     path.append(end)
    #     end = backtrack[end]
    # path.reverse()
    # print(path)
    path_50 = [(0, 1), (0, 2), (1, 7), (2, 10), (3, 12), (5, 15), (9, 19), (13, 22), (15, 23), (18, 24), (23, 25), (27, 25), (32, 24), (35, 23), (37, 22), (41, 19), (45, 15), (47, 12), (48, 10), (49, 7), (50, 2), (50, 1)]

    path_100 = [(0, 1), (0, 3), (1, 10), (2, 14), (3, 17), (5, 22), (6, 24), (9, 29), (13, 34), (16, 37), (21, 41), (26, 44), (28, 45), (33, 47), (36, 48), (40, 49), (47, 50), (48, 50), (49, 50), (50, 50), (51, 50), (52, 50), (53, 50), (60, 49), (64, 48), (67, 47), (72, 45), (74, 44), (79, 41), (84, 37), (87, 34), (91, 29), (94, 24), (95, 22), (97, 17), (98, 14), (99, 10), (100, 3), (100, 2), (100, 1)]
    # # plot these points and draw lines between them
    path_10 = [(0, 1), (1, 3), (2, 4), (4, 5), (6, 5), (8, 4), (9, 3), (10, 1)]

    path_500 = [(0, 1), (0, 3), (0, 7), (1, 23), (2, 32), (3, 39), (4, 45), (5, 50), (7, 59), (8, 63), (9, 67), (12, 77), (14, 83), (17, 91), (19, 96), (23, 105), (29, 117), (34, 126), (37, 131), (42, 139), (44, 142), (49, 149), (52, 153), (56, 158), (61, 164), (70, 174), (76, 180), (86, 189), (92, 194), (97, 198), (101, 201), (108, 206), (111, 208), (119, 213), (124, 216), (133, 221), (137, 223), (145, 227), (154, 231), (159, 233), (167, 236), (173, 238), (183, 241), (191, 243), (200, 245), (205, 246), (211, 247), (218, 248), (227, 249), (243, 250), (244, 250), (245, 250), (246, 250), (247, 250), (248, 250), (249, 250), (250, 250), (251, 250), (252, 250), (253, 250), (254, 250), (255, 250), (256, 250), (257, 250), (273, 249), (282, 248), (289, 247), (295, 246), (300, 245), (309, 243), (317, 241), (327, 238), (333, 236), (341, 233), (346, 231), (355, 227), (363, 223), (367, 221), (376, 216), (381, 213), (389, 208), (392, 206), (399, 201), (403, 198), (408, 194), (414, 189), (424, 180), (430, 174), (439, 164), (444, 158), (448, 153), (451, 149), (456, 142), (458, 139), (463, 131), (466, 126), (471, 117), (477, 105), (481, 96), (483, 91), (486, 83), (488, 77), (491, 67), (493, 59), (495, 50), (496, 45), (497, 39), (498, 32), (499, 23), (500, 7), (500, 6), (500, 5), (500, 4), (500, 3), (500, 2), (500, 1)]

    # d = 500
    # lx, ly = 0, 1
    # for x, y in path_500[1:]:
    #     print((x - lx) / d, (y - ly) / d)
    #     if x == d // 2:
    #         break
    #     lx, ly = x, y
        

    # print(len(path_10))
    # print(len(path_50))
    # print(len(path_100))
    # 12.43050959063111 - 500
    # 12.43050959063111

    # 18.421734951384
    # 18.421041470543468
    # print(len(path_500))
    x1, y1 = [x for x, y in path_100], [y for x, y in path_100]
    x2, y2 = [x for x, y in path_500], [y for x, y in path_500]

    for i in range(len(x2)):
        x2[i] /= 500
        y2[i] /= 500

    z = np.polyfit(x2, y2, 50)
    p = np.poly1d(z)
    
    # xp = np.linspace(0, 1, 100)
    # plt.plot(xp, p(xp), '-', color='red')
    # # plt.plot(x1, y1, )
    # plt.plot(x2, y2, )

    # plt.show()
    # X, Y = [], []
    # for i in range(4, 50, 1):

    #     space = generate_search_space(i, p, r=5)
    # # space = generate_seach_space_bfs(x2, y2, d, max_size=50000)
    # # print(len(space))

    #     t = find_shortest_space(space, i)
    #     X.append(i)
    #     Y.append(log(i) - t)
    #     print(i)

    # print(Y[-1])
    # plt.plot(X, Y, )
    # plt.show()
    # print(Y)

    # print(t * 2)
    # for x, y in space:
    #     plt.plot(x, y, 'o', color='red', markersize=1)
    # plt.show()
    E = [-0.09396378234865677, 0.12917976896555294, -0.09514621847464921, 0.05900446135260906, -0.042121007419623435, 0.07566202823676038, -0.03150882418740508, 0.06380135561691969, -0.03296527778713143, 0.04707742988640495, -0.025963882177306274, 0.04302898930964538, -0.027373417466574956, 0.033251204349860064, -0.02439560369668614, 0.029671617573589604, -0.022268029190791516, 0.026522134978640644, -0.018181311782843323, 0.026270450787990285, -0.015946266725217484, 0.024875727795037328, -0.016340505196699606, 0.021399822786147382, -0.014039102750022625, 0.021052217061247713, -0.013415240248291216, 0.019374582574699595, -0.010530641528255558, 0.02024101713849813, -0.009732535332333203, 0.019255001540918748, -0.010547813374778059, 0.016851160813336374, -0.009705880392653743, 0.016269606010606896, -0.009978637742640295, 0.014713974847731404, -0.008906539535094016, 0.014623957875099958, -0.008442848650770163, 0.014030007201288441, -0.007680865853403773, 0.013825339367559586, -0.0071826133965906536, 0.013436673806144661]
    # E = np.array(E)
    # E = abs(E)
    x = list(range(4, 50))
    # # Y = [log(i*i)/ (e**(i**.5)) for i in x]
    # z = np.polyfit(x, E, 2)
    # p = np.poly1d(z)
    # xp = np.linspace(4, 45, 100)
    # plt.plot(xp, p(xp), '-', color='red')
    # x, y = [], []
    # for i in range(2, len(E)):
    #     print(E[i] - E[i-2])
    #     x.append(i)
    #     y.append(abs(E[i] - E[i-2]))

    # plt.plot(x, y, )
    # plt.show()
    plt.plot(x, E, )
    # # plt.plot(x, Y, )
    plt.show()

    # def taylor_series_ln(x):
    #     ans = 0
    #     for k in range(1, x+1):
    #         ans += ((-1)**k) / k * (x - 1)**k
    #     return ans
    
    # print(taylor_series_ln(20))
