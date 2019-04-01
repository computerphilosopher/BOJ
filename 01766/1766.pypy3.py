import heapq

n, m = map(int, input().split())

graph =  [ [] for _ in range (n+1) ]
indegree = [0] * (n+1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

pq = []

for i in range(1, len(indegree)):
    if not indegree[i]:
        heapq.heappush(pq, i)

res = []

while pq:
    here = heapq.heappop(pq)
    res.append(here)

    for adj in graph[here]:
        indegree[adj] -= 1

        if not indegree[adj]:
            heapq.heappush(pq, adj)

for node in res:
    print(node, end = " ")