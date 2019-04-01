def max_subarray(arr:list)->int:

    max_current = arr[0]
    max_global = arr[0]

    for i in range(1, len(arr)):
        max_current = max(arr[i], max_current + arr[i])
        max_global = max(max_global, max_current)

    return max_global
        
n = int(input())
arr = list(map(int, input().split()))

print(max_subarray(arr))

