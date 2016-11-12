for counter in range(int(raw_input())):
    n, k = map(int, raw_input().split())
    arr = map(int, raw_input().split())
    min_val = 1001
    max_val = 0
    for i in range(n - k + 1):
        s = 0
        for j in range(i, i + k):
            s = s + arr[j]
        s = s / k
        if(s > max_val):
            max_val = s
        if(s < min_val):
            min_val = s

    print "Data Set " + `counter + 1` + ":"
    print max_val - min_val
