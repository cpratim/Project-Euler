N = 30
S = 50

def step(matrix):
    new_matrix = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if matrix[i][j] == 0:
                continue
            around = int(i > 0) + int(i < N - 1) + int(j > 0) + int(j < N - 1)
            if i > 0:
                new_matrix[i - 1][j] += matrix[i][j] / around
            if i < N - 1:
                new_matrix[i + 1][j] += matrix[i][j] / around
            if j > 0:
                new_matrix[i][j - 1] += matrix[i][j] / around
            if j < N - 1:
                new_matrix[i][j + 1] += matrix[i][j] / around
    return new_matrix

DP = [[1] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        matrix = [[0] * N for _ in range(N)]
        matrix[i][j] = 1
        for _ in range(S):
            matrix = step(matrix)
        for k in range(N):
            for l in range(N):
                DP[k][l] *= (1 - matrix[k][l])

total = 0
for i in range(N):
    for j in range(N):
        total += DP[i][j]
print(total)