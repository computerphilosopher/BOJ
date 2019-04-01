import sys
sys.setrecursionlimit(10**6)

def dfs(start, cur, depth):

    distance[cur] = depth
    cycle_start_idx[cur] = start

    next_node = students[cur] - 1

    if distance[next_node] == -1:
        return dfs(start, next_node, depth+1)

    elif cycle_start_idx[next_node] == start:
        return depth - distance[next_node] + 1

    return 0


T = int(input())

for t in range(T):
    n = int(input())
    students = tuple(map(int, input().split()))

    distance = [-1] * n
    cycle_start_idx = [-1] * n

    ans = n

    for i in range(n):
        if distance[i] == -1:
            ans -= dfs(i, i, 0)

    print(ans)

        
