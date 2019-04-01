import queue

#WASD direction
drow = (-1, 0, 1, 0) 
dcol = (0, -1, 0, 1)

FLOOR = '0'; WALL = '1'; ROW = 0; COL = 1; BROKEN = 2; 

def in_board(board, r, c):

    if r < 0 or c < 0:
        return False

    if r >= len(board) or c >= len(board[r]):
        return False

    return True

def bfs(board, dest):

    #튜플의 값은 차례대로 행, 열, 벽을 부순 적이 있는지 여부를 나타냄

    if (0, 0) == dest:
        return 1

    start = (0, 0, 0)
     

    q = [start]

    dist = {}

    #거리는 첫 칸을 포함한다고 했으므로 1로 초기화
    dist[start] = 1

    while q:
        here = q.pop(0)

        r = here[ROW]; c = here[COL]; broken = here[BROKEN]; 
        d = dist[here]

        for i in range(4):
            nr = r + drow[i]
            nc = c + dcol[i]

            if in_board(board, nr, nc) and (nr, nc, broken) not in dist:

                if (nr,nc) == dest:
                    return d+1

                #인접한 칸이 벽이 아니라면 그대로 큐에 넣는다.
                elif board[nr][nc] == FLOOR:
                    dist[(nr, nc, broken)] = d+1
                    q.append((nr, nc, broken))

                #인접한 칸이 벽이고 아직 벽을 부순 적이 없다면 벽을 부순 것으로 처리하고 큐에 넣는다.
                elif not broken:
                    dist[(nr, nc, 0)] = float('inf')
                    dist[(nr,nc, 1)] = d+1
                    q.append((nr, nc, 1))
                    
    return -1

rows, cols = map(int, input().split())
board = []

for i in range(rows):
    tmp = input()
    board.append(tmp)


print(bfs(board, (rows-1, cols-1)))

