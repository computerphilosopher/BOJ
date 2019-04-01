import collections

#WASD
drow = (-1, 0, 1, 0) 
dcol = (0, -1, 0, 1) 

def in_board(r, c):
    if r<0 or c < 0:
        return False

    if r >= len(board) or c >= len(board[r]):
        return False

    return True

def bfs():
    q = collections.deque()
    q.append((0, 0))

    distance = dict()

    distance[(0, 0)] = 1

    while q:
        here = q.popleft()

        if here == (rows-1, cols-1):
            return distance[here]
        
        for i in range(4):

            next_row = here[0] + drow[i]
            next_col = here[1] + dcol[i]

            if in_board(next_row, next_col) and (next_row, next_col) not in distance:
                if board[next_row][next_col] == '1':
                    q.append((next_row, next_col))
                    distance[(next_row, next_col)] = distance[here] + 1
            
        

rows, cols = map(int, input().split())
board = []

for i in range(rows):
    line = input()
    board.append(line)

print(bfs()) 