for i in range(int(raw_input())):
    hp = int(raw_input())
    b_hp = bin(hp)

    n = 0
    while(hp != 1):
        b_hp = bin(hp)
        if(b_hp.count('1') != 1):
            b_hp = b_hp[0:2] + b_hp[3:]
            hp = int(b_hp[2:], 2)
        else:
            hp /= 2
        n += 1
    if(n % 2 == 0):
        print "Divyanshu"
    else:
        print "Aayush"
