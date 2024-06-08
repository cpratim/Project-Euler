import matplotlib.pyplot as plt


def search_pos(limit, val):

    V = len(str(val))

    def dp(i, u):

        if i == len(limit):
            return 0
        total = 0

        if i + V > len(limit):
            return 0
        
        if u:
            sub = int(limit[i:i+V])
            if val < sub:
                total += 1 + sub * dp(i+V, False) + dp(i+V, True)
            else:
                total += sub * dp(i+V, False) + dp(i+V, True)
        else:
            total += 1 + (10**V-1) * dp(i+V, False)
        return total
    
    return dp(0, True)

X, y = [], []
limit = ''
i = 1
while len(limit) < 111111365:
    limit += str(i)
    X.append(len(limit))
    y.append(i)
    i += 1

plt.plot(X, y)
plt.show()
