from collections import deque

#box state
EMPTY = -1
NOT_YET = 0
RIPE = 1
    
#WASD
drow = (-1, 0, 1, 0)
dcol = (0, -1, 0, 1)

def in_box(r, c)->bool:
    if r<0 or c<0 or r>=rows or c>=cols:
        return False
    return True

def bfs()->int:

    dist = [ [ float('inf') for j in range(cols) ] for i in range(rows) ]
    q = deque()

    for i in range(rows): 
        for j in range(cols):
            if box[i][j] == RIPE:
                q.append((i,j))
                dist[i][j] = 0

    while q:
        here = q.popleft()
        cur_row, cur_col = here[0], here[1]

        for i in range(4):
            next_row, next_col = cur_row + drow[i], cur_col + dcol[i]

            if in_box(next_row, next_col) and dist[next_row][next_col] == float('inf'):
                if box[next_row][next_col] == NOT_YET:
                    q.append((next_row, next_col))
                    dist[next_row][next_col] = 1 + dist[cur_row][cur_col]

    ret = -1

    for i in range(rows):
        for j in range(cols):
            if box[i][j] != EMPTY:
                ret = max(ret, dist[i][j])
                if ret == float('inf'): return -1

    return ret


cols, rows = map(int, input().split())
box = []

for i in range(rows):
    line = list(map(int, input().split()))
    box.append(line)

print(bfs())