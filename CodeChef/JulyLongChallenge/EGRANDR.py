for i in range(int(raw_input())):
    dis = int(raw_input())
    n = map(int, raw_input().split())
    s = 0
    flag = False
    full = False
    
    for marks in n:
        if marks == 2:
            flag = True
            break
        else:
            if marks == 5:
                full = True
            s = s + marks

    if flag or not full:
        print "No"
    else:
        avg = s / len(n)
        if avg < 4:
            print "No"
        else:
            print "Yes"
