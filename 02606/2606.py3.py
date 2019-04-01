import collections


def dfs(here:int):

    visited.add(here)

    ret = 0

    for adj in graph[here]:
        if adj not in visited:
            ret += dfs(adj)

    return 1 + ret
    
node_count = int(input())
edge_count = int(input())

graph = [ []  for i in range(node_count+1)]

for i in range(edge_count):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

    visited = set()

print(dfs(1)-1)
