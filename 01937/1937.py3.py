import sys
sys.setrecursionlimit(10**6)

dr = [0, -1, 0, 1] #WASD
dc = [1, 0, -1, 0] #WASD

memo = {}

def in_forest(row, col):
    if row >= n or col >= n or row < 0 or col < 0:
        return False
    return True

def solve(forest, row, col):
    
    if (row,col) in memo:
        return memo[(row,col)]

    ret = 0 

    for i in range(4):
        next_row = row + dr[i]
        next_col = col + dc[i]

        if in_forest(next_row, next_col) and forest[next_row][next_col] > forest[row][col]:
            ret = max(ret, solve(forest, next_row, next_col))

    memo[(row, col)] = ret + 1
    return ret+1


n = int(input())

forest = []

for i in range(n):
    line = list(map(int, input().split()))
    forest.append(line)

ret = 0 

for i in range(n):
    for j in range(n):
        ret = max(ret, solve(forest, i, j))

print(ret)
