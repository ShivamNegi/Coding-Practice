def check(num):
    for i in xrange(100, 1000):
        if num % i == 0:
            if len(str(num / i)) == 3:
                return True
    return False

for i in range(int(raw_input())):
    no = int(raw_input())

    for j in xrange(no - 1, 1, -1):
        num = str(j)
        if num == num[::-1]:
            if check(j):
                print j
                break
