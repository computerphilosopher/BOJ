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

    #dist [벽 부쉈는지][행][열]
    dist = [ [ [-1 for k in range(len(board[0]))] for j in range(len(board))] for i in range(2) ]

    #거리는 첫 칸을 포함한다고 했으므로 1로 초기화
    dist[0][0][0] = 1

    while q:
        here = q.pop(0)

        r = here[ROW]; c = here[COL]; broken = here[BROKEN]; 
        d = dist[broken][r][c]

        for i in range(4):
            nr = r + drow[i]
            nc = c + dcol[i]

            if in_board(board, nr, nc) and dist[broken][nr][nc] == -1:

                if (nr,nc) == dest:
                    return d+1

                #인접한 칸이 벽이 아니라면 그대로 큐에 넣는다.
                elif board[nr][nc] == FLOOR:
                    dist[broken][nr][nc] = d+1
                    q.append((nr, nc, broken))

                #인접한 칸이 벽이고 아직 벽을 부순 적이 없다면 벽을 부순 것으로 처리하고 큐에 넣는다.
                elif not broken:
                    dist[0][nr][nc] = float('inf')
                    dist[1][nr][nc] = d+1
                    q.append((nr, nc, 1))
                    
    return -1

rows, cols = map(int, input().split())
board = []

for i in range(rows):
    tmp = input()
    board.append(tmp)


print(bfs(board, (rows-1, cols-1)))

