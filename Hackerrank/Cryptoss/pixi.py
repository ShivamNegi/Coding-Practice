from math import ceil

SIZE = 100
v, n, m = map(int, input().split())

def display(grid):
    for row in grid:
        print(row)

def compute(incr_x, incr_y, points):
    # grid = [[0]*10]*10
    grid = [[0 for x in range(SIZE)] for y in range(SIZE)]

    for i in range(len(points)):
        points[i][0] += incr_x
        points[i][1] += incr_y
        # for j in range(len(points[i])):

    for a, b in points:
        n1 = ceil(a / n)
        n2 = ceil(b / m)
        if n1 == a / n:
            grid[n1][n2] += 1
            grid[n1 + 1][n2] += 1
        if n2 == b / m:
            grid[n1][n2 + 1] += 1
        if n1 == a / n and n2 == b / m:
            grid[n1 + 1][n2 + 1] += 1

    display(grid)

points = []

for i in range(v):
    a, b = map(int, input().split())
    points.append([a, b])

print (points)
for i in range(n + 1):
    for j in range(m + 1):
        compute(i, j, points)
        print
