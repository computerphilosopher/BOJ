def solve(arr:list, city:int)->int:

    i = 0
    ret = 0

    while i < len(arr):

        if arr[i] <= city <= arr[i+1]:
            ret += 1

        i += 2

    return ret

t = int(input())

for tc in range(t):
    if tc > 0:
        input()

    n = int(input())
    arr = list(map(int, input().split()))

    print("Case #%d: "%(tc+1), end = "")

    p = int(input())

    for i in range(p):
        city = int(input())
        print(solve(arr, city), end = " ")

    print("")