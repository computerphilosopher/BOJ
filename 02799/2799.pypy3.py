GRIDS = 4

def count_blind(building, r, c):

    ret = 0
    for i in range(GRIDS):
        if building[r+i][c] == '*':
            ret += 1
    return ret 

def search_windows(building, floors, windows):

    r = c = 1
    ret = [0] * 5
    window_count = 1
    floor_count = 1

    while(floor_count <= floors):
        tmp = count_blind(building, r, c)
        ret[tmp] += 1

        if window_count < windows:
            window_count += 1
            c += GRIDS+1
        else:
            window_count = 1
            floor_count += 1
            r += GRIDS+1
            c = 1

    return ret
            

floors, windows = map(int, input().split())

building = []

for i in range(5 * floors + 1):
    line = input()
    building.append(line)

ans = search_windows(building, floors, windows)

for num in ans:
    print(num, end = " ")