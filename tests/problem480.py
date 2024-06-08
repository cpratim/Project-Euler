from functools import lru_cache
from pprint import pprint
from math import log2, floor

chars = 'thereisasyetinsufficientdataforameaningfulanswer'
charset = 'abcdefghijklmnopqrstuvwxyz'

counts = {c: 0 for c in chars}
positions = {c: 0 for c in charset}

def is_empty():
    for c in counts:
        if counts[c] > 0:
            return False
    return True

@lru_cache(maxsize=None)
def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n-1)

def get_permutations():
    total = factorial(sum(counts.values()))
    for c in counts:
        total //= factorial(counts[c])
    return total


for i in range(len(charset)):
    positions[charset[i]] = i

for c in chars:
    counts[c] += 1

def get_hash():
    h = ""
    for c in counts:
        h += c + str(counts[c]) 
    return h


def get_position(word):

    cache = {}
    def get_num_less(i, j, n, upper_limit):
        if i == n:
            return 0
        h = get_hash()
        if h in cache:
            # print('cache hit')
            return cache[h]
        total = 0
        if j < len(word):
            for c in counts:
                if not counts[c]:
                    continue
                if upper_limit and positions[c] > positions[word[j]]:
                    # print(c, positions[c], positions[word[j]])
                    continue
                total += 1
                counts[c] -= 1
                total += get_num_less(i+1, j+1, n, upper_limit and positions[c] == positions[word[i]])
                counts[c] += 1
        else:
            if upper_limit:
                return 0
            for c in counts:
                if not counts[c]:
                    continue
                total += 1
                counts[c] -= 1
                total += get_num_less(i+1, j, n, upper_limit)
                counts[c] += 1
        cache[h] = total
        return total
    
    return get_num_less(0, 0, 15, True)


# Example usage
char_counts = {'a': 3, 'b': 2, 'c': 4, 'd': 6}  # Example character counts
word_length = 15
# count_permutations(char_counts, word_length)


if __name__ == '__main__':
    # print(count_words_with_char_limits(char_counts, word_length))
    print(max(counts.values()))
    print(len(counts))

    v = 1
    for c in counts:
        v *= (counts[c] + 1)
    print(v)