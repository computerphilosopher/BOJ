def lis(start:int)->int:
    if start in memo:
        return memo[start]

    ret = T[start]

    for i in range(start+1, len(T)):
        if T[start] < T[i]:
            ret = max(ret,  T[start] + lis(i))

    memo[start] = ret
    return ret

def solve(T:tuple)->int:

    ret = -1
    for i in range(len(T)):
        ret = max(ret, lis(i))

    return ret


    

n = int(input())

T = tuple(map(int, input().split()))

memo = {}

print(solve(T))


