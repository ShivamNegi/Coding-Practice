from string import ascii_lowercase as l

for t in range(int(raw_input())):
    no = int(raw_input())
    out = l * (no / 26)
    out = out + l[0: no%26]
    print out
