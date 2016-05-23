inp = raw_input()
l = len(inp)

def isTandom(inp):
	l1 = len(inp)
	size = l1 / 3

	if(inp[:size] == inp[size: 2 * size] == inp[2 * size:]):
		return True
	else:
		return False

countint = 0
countbore = 0

for i in range(l - 2):
	for j in range(i + 2, l, 3):
		if isTandom(inp[i:j + 1]):
			try:
				if inp[i] != inp[j + 2]:
					countint = countint + 1
				else:
					countbore = countbore + 1
			except:
				countint = countint + 1

print countint, countbore
