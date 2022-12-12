import time

def dijkstras(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    unvisited = {}
    for r in range(rows):
        for c in range(cols):
            unvisited[(r, c)] = float('inf')
    unvisited[(0, 0)] = matrix[0][0]

    sums = [[float('inf')] * cols for i in range(rows)]
    sums[0][0] = matrix[0][0]

    start = (0, 0)
    while True:
        x, y = start
        for (r, c) in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if r < 0 or r >= rows or c < 0 or c >= cols:
                continue
            if (r, c) in unvisited:
                val = min(sums[r][c], sums[x][y] + matrix[r][c])
                sums[r][c] = val
                unvisited[(r, c)] = val
        
        del unvisited[(x, y)]

        if not unvisited:
            break 

        start = min(unvisited.keys(), key=lambda x: unvisited[x])
    
    return sums[rows - 1][cols - 1]

start = time.time()
f = open('misc/p083_matrix.txt', 'r')
matrix = [[int(i) for i in line.split(',')] for line in f.readlines()]
f.close()
print(dijkstras(matrix))
end = time.time()
print(end - start)
