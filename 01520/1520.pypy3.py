from sys import setrecursionlimit
from collections import deque

setrecursionlimit(10**7)

directions = ( (-1, 0), (1, 0), (0, -1), (0, 1))
cache = dict()

def in_board(here):
    r, c = here[0], here[1]
    return 0 <= r < rows and 0 <= c < cols

def solve(here):

    if here == (rows-1, cols-1):
        return 1

    if here in cache:
        return cache[here]

    r, c= here[0], here[1]

    path_count = 0
    for d in directions:
        nr, nc = r+d[0], c+d[1]
        there = (nr, nc)

        if in_board(there) and board[r][c] > board[nr][nc]:
            path_count += solve(there)
    
    cache[here] = path_count
    return path_count


rows, cols = map(int,input().split())
board = []

for i in range(rows):
    board.append(tuple(map(int, input().split())))

print(solve((0,0)))