def sum_of_digits(n):
  return sum(map(int, str(n)))

a = []
n = 30
for b in range(2, 100):
    for e in range(2, 10):
        p = b ** e
        if sum_of_digits(p) == b: a.append(p)

a.sort()
print(a[n - 1])

