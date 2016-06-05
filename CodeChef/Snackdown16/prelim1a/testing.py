def getarr(no, size):
    arr = []
    for i in range(1, size):
        arr.append(no * i)
    return arr

no1 = int(raw_input())
no2 = int(raw_input())
arr1 = getarr(no1, 20)
arr2 = getarr(no2, 20)

min = no1 * no2

for n1 in arr1:
    for n2 in arr2:
        if abs(n1 - n2) < min:
            min = abs(n1 - n2)

print min
