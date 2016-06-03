from itertools import combinations

inp = map(int, raw_input().split())
n = inp[0]
x = inp[1]
inp = map(int, raw_input().split())
counter = 0

for i in range(len(inp)):
    for no in combinations(inp, i):
        sum = 0
        for n in no:
            sum = sum ^ n
        if sum == x:
            counter = counter + 1

print counter
