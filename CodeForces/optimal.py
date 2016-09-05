n = int(raw_input())
res = map(int, raw_input().split())
l = len(res)
res = sum(res)
val = round(res / l)
sub = 0
if res / l - int(res / l) == 0.5:
    sub = 1
print int(val - sub)
