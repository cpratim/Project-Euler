N = 5
init = [0] * (2**N)

# 32 rotations, each rotation is a 5 digit number
# there are 32 possible 5 digit numbers and 32 rotations
# so valid circle iff all 32 numbers are in the circle

# 00000
# 00001
# 0001y
# 001yz
# ...

# the previous 4 digits are set by the previous 5-digit subsequence
# the circle has to start with 5 0's
# the last 4 subsequences are special in that they connect with
# the start of the array

seen = set()
seen.add(tuple([0] * N))

solution = 0

def backtrack(bitarray, idx):
    global solution
    if idx == len(bitarray) - N + 1:
        for i in range(N - 1):
            if tuple(bitarray[idx + i:] + bitarray[:i + 1]) in seen:
                return
        # print("".join(str(x) for x in bitarray), int("".join(str(x) for x in bitarray), 2))
        solution += int("".join(str(x) for x in bitarray), 2)
        return

    bitarray[idx + N - 1] = 0
    if tuple(bitarray[idx:idx + N]) not in seen:
        seen.add(tuple(bitarray[idx:idx + N]))
        backtrack(bitarray, idx + 1)
        seen.discard(tuple(bitarray[idx:idx + N]))

    bitarray[idx + N - 1] = 1
    if tuple(bitarray[idx:idx + N]) not in seen:
        seen.add(tuple(bitarray[idx:idx + N]))
        backtrack(bitarray, idx + 1)
        seen.discard(tuple(bitarray[idx:idx + N]))

backtrack(init, 1)
print(f"solution: {solution}")