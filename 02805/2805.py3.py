from sys import setrecursionlimit
setrecursionlimit(10**9)

#INPUT_LIMIT = 2000000000

def solve(trees, m, low, high):

    #이분탐색 끝
    if low > high:
        return -float('inf')

    mid = (low + high)//2
    cut = 0

    for tree in trees:
        if tree > mid:
            cut += tree - mid

    #나무가 충분하지 않으면 절단기의 높이를 낮춘다.
    if cut < m:
        left = solve(trees, m, low,mid-1)
        return left 
    
    right = solve(trees, m,mid+1,high)

    return max(mid, right)
    

n, m = map(int, input().split())
trees = list(map(int, input().split()))

#print(solve(trees, m, 1, INPUT_LIMIT))
print(solve(trees, m, 0, max(trees)))