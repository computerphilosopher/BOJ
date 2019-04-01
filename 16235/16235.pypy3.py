import collections

drow = (-1, -1, -1, 0, 0, 1, 1, 1)
dcol = (-1, 0, 1, -1, 1, -1, 0, 1)

row_count, tree_count, total_years = map(int, input().split())
col_count = row_count

food_supply = [] 

forest = [ [  collections.deque()  for j in range(col_count) ]  for i in range(row_count)]   
foods = [ [5] * col_count for i in range(row_count)]   


for i in range(row_count):
    line = tuple(map(int, input().split()))
    food_supply.append(line)


for i in range(tree_count):
    rows, cols, year = map(int, input().split())
    forest[rows-1][cols-1].append(year)


def eat_food():

    global tree_count

    for i in range(row_count):
        for j in range(col_count):
            trees = forest[i][j]
            need_pop = 0

            for k in range(len(trees)-1, -1, -1):

                if foods[i][j] >= trees[k]:
                    foods[i][j] -= trees[k]
                    trees[k] += 1
                 
                else:
                    need_pop = k+1
                    break

            for k in range(need_pop):
                tree_count -= 1
                foods[i][j] += (trees[0])//2
                trees.popleft()
                
def add_food():

    for i in range(row_count):
        for j in range(col_count):
            foods[i][j] += food_supply[i][j]

def in_forest(r, c):
    
    if r < 0 or c < 0:
        return False

    if r >= row_count or c >= col_count:
        return False

    return True

def make_child(r, c, years):

    global tree_count

    if years % 5:
        return
    
    for i in range(8):
        nr = r + drow[i]
        nc = c + dcol[i]

        if(in_forest(nr, nc)):
            forest[nr][nc].append(1)
            tree_count += 1

def solve():

    for t in range(total_years):

        eat_food()

        for i in range(row_count):
            for j in range(col_count):
                for k in range(len(forest[i][j])):
                    make_child(i, j, forest[i][j][k])

        add_food()




solve()

print(tree_count)