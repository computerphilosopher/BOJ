from sys import stdin
from sys import setrecursionlimit

setrecursionlimit(10**7)

def solve(low, high):
    if low > high:
        return float('inf')
        
    disks = 0
    cur_sum = 0

    mid = (low+high)//2

    for lesson in lessons:

        if cur_sum + lesson > mid:
            disks += 1
            cur_sum = 0
        cur_sum += lesson

    if cur_sum > 0: disks += 1
    if disks > M:
        return solve(mid+1, high)

    return min(mid, solve(low, mid-1))
    

N, M = map(int, stdin.readline().split())
lessons = tuple(map(int, stdin.readline().split()))

print(solve(max(lessons), 1000000**2))