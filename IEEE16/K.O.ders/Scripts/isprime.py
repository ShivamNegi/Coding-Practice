from math import sqrt

def isprime(no):
	if no == 1:
		return False
	for i in range(2, int(sqrt(no))):
		if no % i == 0:
			return False
	return True
