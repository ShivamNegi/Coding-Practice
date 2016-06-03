t = int(raw_input())

for i in range(t):
    inp = raw_input()
    inp = inp.split("$")[1]
    no = ""
    for ch in inp:
        if ch.isalpha():
            break
        elif ch.isdigit():
            no = no + ch
    no = int(no)
    print "$" + `no`
