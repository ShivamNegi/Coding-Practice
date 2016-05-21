from math import sqrt

def isprime(n):
	for i in range(2, int(sqrt(n)) + 1):
		if n % i == 0:
			return False
	return True

n = int(raw_input())
arr = []

for i in range(n):
	no = int(raw_input())
	arr.append(no)

no = max(arr)

fib = [0, 1]

while fib[-1] < no:
	fib.append(fib[-1] + fib[-2])

for n in arr:
	s = 0
	for i in range(1, n):
		if i not in fib:
			s = s + i
	if isprime(s):
		print 'Tic'
	elif s % 2 == 0:
		print 'Tac'
	else:
		print 'Toe'
	


