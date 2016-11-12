from collections import Counter as c
from string import ascii_lowercase as l

para = raw_input().lower()
a = c(para)

for ch in l:
    if a[ch]:
        print ch.upper(), ":", a[ch]
