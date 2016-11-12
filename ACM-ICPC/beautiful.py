for test in range(int(raw_input())):
    n = int(raw_input())
    arr = map(int, raw_input().split())

    if n == 1:
        print "yes"
    else:
        if n == 2:
            zero = arr.count(0)
            one = arr.count(1)

            if n - (zero + one) < 2:
                print "yes"
            else:
                print "no"
        else:
            zero = arr.count(0)
            one = arr.count(1)
            neg = arr.count(-1)
            val = zero + one

            if n - val < 2:
                print "yes"
            else:
                if neg > 1:
                    if one > 0:
                        val = val + neg
                        if n == val:
                            print "yes"
                        else:
                            print "no"
                    else:
                        print "no"
                else:
                    print "no"
