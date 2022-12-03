from pprint import pprint

D = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000,
}

def roman_to_int(s):
    n = 0
    for i in range(len(s)):
        if i > 0 and D[s[i]] > D[s[i-1]]:
            n += D[s[i]] - 2 * D[s[i-1]]
        else:
            n += D[s[i]]
    return n


def int_to_roman(n):
    s = ''
    for r in (('M', 1000), ('CM', 900), ('D', 500), ('CD', 400),
              ('C', 100), ('XC', 90), ('L', 50), ('XL', 40),
              ('X', 10), ('IX', 9), ('V', 5), ('IV', 4), ('I', 1)):
        s += r[0] * (n // r[1])
        n %= r[1]
    return s


with open('../misc/p089_roman.txt') as f:
    data = f.read().splitlines()

total = 0
for line in data:
    n = roman_to_int(line)
    total += len(line) - len(int_to_roman(n))

print(total)

