STATE, TWISTED = 0, 1
ROTATION = 1
DIRECTION, A, B = 0, 1, 2

def solve(belts):
    #int i = 0
    prev = (0, 1)
    cur = ()

    for belt in belts:
        if belt[STATE] == TWISTED:
            prev = (int(not prev[DIRECTION]), prev[ROTATION])  
        cur = (prev[DIRECTION], prev[ROTATION] * belt[B] // belt[A])
        prev = cur

    return cur



m = int(input())
belts = []

for i in range(m):
    belt = list(map(int, input().split()))
    belt = (belt[2], belt[0], belt[1])
    belts.append(belt)

ans = solve(belts)

print(ans[0], ans[1])