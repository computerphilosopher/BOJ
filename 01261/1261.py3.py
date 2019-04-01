from collections import deque
import heapq

#상하좌우
direction = ((-1, 0), (1, 0), (0, -1), (0, 1))
ROOM = 0
WALL = 1

def in_board(pos):
    r , c = pos[0], pos[1]
    return r >= 0 and c >=0 and r < rows and c < cols


def bfs(board):
    q = deque()
    dist =dict()

    start = (0, 0) #row, col, break_count
    q.append(start)
    dist[start] = 0

    dest = (rows-1, cols-1)
    min_break = float('inf')

    while q:

        here = q.popleft()
        r, c= here[0], here[1]

        #목적지에 갈 수 있는 길 중 부수기 횟수가 최소인 것을 갱신 
        if here == dest:
            min_break = min(dist[here], dist[here] + board[r][c])

        for d in direction:
            nr, nc, = r + d[0], c + d[1]
            there = (nr, nc)

            if in_board(there):

                # 기존에 발견한 경로보다 가까울 때만 큐에 넣는다. 새롭게 찾은 길이라면 무한대로 초기화.
                if there not in dist: dist[there] = float('inf')

                if dist[there] > dist[here] + board[nr][nc]:
                    dist[there] = dist[here] + board[nr][nc]
                    q.append(there)
    
    return min_break

cols, rows= map(int, input().split())
board = []

for i in range(rows):
    board.append(list(map(int ,input())))

print(bfs(board))