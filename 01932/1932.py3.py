def solve_recursive(row:int, col:int)->int:


    if row == len(triangle)-1:
        return triangle[row][col]

    if (row, col) in cache:
        return cache[(row, col)]

    cache[(row,col)] = triangle[row][col] + max(solve_recursive(row+1, col), solve_recursive(row+1, col+1))

    return cache[(row,col)]


n = int(input())
triangle = []
cache = dict()

for i in range(n):
    floor = list(map(int, input().split()))
    triangle.append(floor)

print(solve_recursive(0, 0))

