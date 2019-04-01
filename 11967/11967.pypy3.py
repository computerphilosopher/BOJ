from collections import deque
from sys import setrecursionlimit

setrecursionlimit(10**7)
directions = ( (-1, 0), (1, 0), (0, -1), (0, 1))

def in_board(r, c):
    return r < N and c < N and r >=0 and c >= 0

def dfs(here, visited):

    visited.add(here)
    lighten.add(here)
    r, c = here[0], here[1]

    switches = board[r][c]

    for switch in switches:
        lighten.add(switch)

    for d in directions:
        nr, nc = r + d[0], c + d[1]
        there = (nr, nc)

        if in_board(nr, nc) and there not in visited and there in lighten:
            dfs(there,visited)


def solve():

    l = len(lighten)
    start = (0,0)

    while True:
        dfs(start, set())
        if l == len(lighten):
            break
        l = len(lighten)
    
    return len(lighten)


N, M = map(int, input().split())
board = [  [ [] for _ in range(N) ] for j in range(N) ]
lighten = {(0,0)}

for _ in range(M):
    x, y, a, b = map(int, input().split())
    board[x-1][y-1].append((a-1, b-1))

print(solve())