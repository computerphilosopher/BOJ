from collections import deque
directions = ( (1, 0), (-1, 0), (0, -1), (0, 1) )

def in_board(here):
    r, c= here[0], here[1]
    return r >= 0 and c >= 0 and r < N and c < N

def bfs(start,shark_size):
    q = deque()
    dist = dict()

    q.append(start)
    dist[start] = 0

    fishes = []

    while q:
        here = q.popleft()
        r, c = here[0], here[1]
        if board[r][c] and shark_size > board[r][c]: 
            fishes.append((dist[here], r, c))

        for d in directions:
            nr, nc = r + d[0], c + d[1]
            there = (nr, nc)

            if in_board(there) and there not in dist:
                if shark_size >= board[nr][nc]:
                    q.append(there)
                    dist[there] = dist[here] + 1
    
    return sorted(fishes)

def solve():
    shark_size = 2
    feed_count = 0
    cur = start
    time = 0

    while True:
        fishes = bfs(cur, shark_size)
        '''
        print()
        print("time", time, "level:", shark_size)
        for i in range(N):
            for j in range(N):
                print(board[i][j], end = " ")
            print("")
        print(fishes)
        '''
        if not fishes: break
        
        time += fishes[0][0]
        cur = (fishes[0][1], fishes[0][2])
        feed_count += 1

        if feed_count == shark_size:
            shark_size += 1
            feed_count = 0
        
        board[cur[0]][cur[1]] = 0
    
    return time



N = int(input())
board = []

for i in range(N):
    line = list(map(int, input().split()))
    board.append(line)

start = 0
for i in range(N):
    for j in range(N):
        if board[i][j] == 9: board[i][j] = 0; start = (i,j)

print(solve())