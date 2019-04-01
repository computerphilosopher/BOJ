from collections import deque

target = ( (1, 2, 3),
           (4, 5, 6,),
           (7, 8, 0,),
           ) 
# hjkl
drow = [0, 1, -1, 0]
dcol = [-1, 0, 0, 1]

rows = 3
cols = 3

def in_board(r, c):
    if r < 0 or c < 0 or r >= rows or c >= cols:
        return False 
    return True

def bfs(start:tuple):
    
    q = deque()
    d = dict()

    q.append(start)
    d[start] = 0

    while q:

        here = q.popleft()

        if here == target:
            return d[here]
        
        for i in range(rows):
            for j in range(cols):
                if not here[i][j]:
                    for k in range(4):
                        swap_row, swap_col = i + drow[k] , j + dcol[k]
                        next_node = list(map(list, here))

                        if in_board(swap_row, swap_col):
                            next_node[i][j], next_node[swap_row][swap_col] = next_node[swap_row][swap_col], next_node[i][j]
                            next_node = tuple(map(tuple, next_node))

                            if next_node not in d:
                                q.append(next_node)
                                d[next_node] = d[here] + 1


    return -1



board = []

for i in range(3):
    line = tuple(map(int, input().split()))
    board.append(line)

print(bfs(tuple(board)))
