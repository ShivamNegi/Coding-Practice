word = raw_input()
for k in range(int(raw_input())):
    sub = raw_input()
    flag = True
    for ch in sub:
        if ch in word:
            pass
        else:
            print "No"
            flag = False
            break

    if flag:
        print "Yes"
