
def solve(low, high):

    if(low >= high):
        return -float('inf')

    mid = (low + high)//2

    s = 0

    for cost in request:
        if cost > mid:
            s += mid
        else:
            s += cost

    if s > budget:
        return solve(low, mid)

    return max(mid, solve(mid+1, high))


n = int(input())

request = list(map(int, input().split()))

budget = int(input())

s = sum(request)

if s <= budget:
    print(max(request))

else:
    print(solve(0, budget))

