def solve(board, start_row, start_col, start_num, rows, cols, k):
    
    if(k > len(board) * len(board[0])):
        return 0

    if(rows <= 0 or cols <=0):
        return 0

    for i in range(start_row+rows-1, start_row-1, -1):
        board[i][start_col] = start_num
        if(start_num == k):
            return len(board)-i, start_col+1
        start_num +=1

    for j in range(start_col+1, start_col + cols):
        board[start_row][j] = start_num
        if(start_num == k):
            return len(board)-i, j+1
        start_num +=1

    for i in range(start_row+1, start_row+rows):
        board[i][start_col+cols-1] = start_num
        if(start_num == k):
            return len(board)-i, start_col+cols  
        start_num += 1
    
    for j in range(start_col + cols-2, start_col, -1):
        board[start_row+rows-1][j] = start_num
        if(start_num == k):
            return len(board) - (start_row+rows-1), j+1
        start_num += 1
         

    return solve(board, start_row+1, start_col+1, start_num, rows-2, cols-2, k)


cols, rows = map(int, input().split())
k = int(input())

board = [ [0] * cols for _ in range(rows)]

solution = solve(board, 0, 0, 1, rows, cols, k)

if solution != 0:
    print("%d %d"%(solution[1], solution[0]))

else:
    print(solution)

