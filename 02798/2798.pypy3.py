def solve(arr:tuple, m:int)->int:

    ret = -float('inf') 

    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            for k in range(j+1, len(arr)):
                s = arr[i] + arr[j] + arr[k]
                if(s <= m):
                    ret = max(ret, s)
    return ret

n, m = map(int, input().split())

arr = tuple(map(int, input().split()))

print(solve(arr, m))
