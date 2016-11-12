n = int(raw_input())

a = range(1, n + 1)

# upper_half = range(n / 2 + 1, n + 1)
# lower_half = range(1, n / 2 + 1)

upper_half = range(n / 2, n + 1)
lower_half = range(1, n / 2)
a = lower_half + a + upper_half[::-1]

for no in a:
    print no,
print
