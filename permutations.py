def permutations(lst):
  if len(lst) <= 1:
    return [lst]
  results = []
  for i in range(len(lst)):
    for perm in permutations(lst[:i] + lst[i + 1:]):
      results.append([lst[i]] + perm)
  return results

def print_permutations(a, l, r):
    if l == r:
        print a
    else:
        for i in range(l, r + 1):
            a[l], a[i] = a[i], a[l]
            print_permutations(a, l + 1, r)
            a[l], a[i] = a[i], a[l]


string = "negi"
print_permutations(list(string), 0, len(string) - 1)
