from collections import deque

#WASD
drow = (-1, 0, 1, 0)
dcol = (0, -1, 0, 1)

def in_board(r, c):
    if r<0 or c<0 or r>=rows or c>=cols:
        return False
    return True

def bfs(start:tuple):

    q = deque()
    dist = [ [-1] * cols for i in range(rows)]

    q.append(start)
    dist[start[0]][start[1]] = 0

    while q:
        here = q.popleft()
        r,c = here[0], here[1]

        for i in range(4):
            nr, nc = r + drow[i], c + dcol[i] 
            if nr<0 or nc<0 or nr>=rows or nc>=cols:
                continue

            if dist[nr][nc] == -1:
                if board[nr][nc] == 'L':
                    dist[nr][nc] = dist[r][c] + 1 
                    q.append((nr,nc))
            
    ret = -1

    for row in dist:
        ret = max(ret, max(row))

    return ret

def bfs_all():
    ret=  -1
    for i in range(rows):
        for j in range(cols):
            if board[i][j] == 'L':
                ret = max(ret, bfs((i,j)))

    return ret

rows, cols = map(int, input().split())
board = []
visited = set()

for i in range(rows):
    line = list(input())
    board.append(line)

print(bfs_all())