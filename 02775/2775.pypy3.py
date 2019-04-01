def solve(floor, room_number):

    if floor == 0:
        return room_number

    ret = 0

    for i in range(1, room_number+1):
        ret += solve(floor-1, i) 

    return ret


T = int(input())

for t in range(T):
    floor = int(input())
    room_number = int(input())

    print(solve(floor, room_number))
