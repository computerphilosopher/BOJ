from sys import stdin
from sys import stdout
import heapq

WEIGHT, VERTEX = 0, 1
INF = float('inf')

def dijkstra(graph, start):

    pq = []
    dist = [INF] * (V+1)

    dist[start] = 0
    heapq.heappush(pq, (0, start))

    while pq:
        top = heapq.heappop(pq)
        cost, here = top[WEIGHT], top[VERTEX]

        if dist[here] < cost:
            continue

        for adj in graph[here]:
            next_dist = cost + adj[WEIGHT]
            there = adj[VERTEX]
            if next_dist < dist[there]:
                heapq.heappush(pq, (next_dist, there))
                dist[adj[VERTEX]] = next_dist
    
    return dist



V, E = map(int, stdin.readline().split())
K = int(stdin.readline())

graph = [ [] for _ in range(V+1) ]

for _ in range(E):
    u, v, w = map(int, stdin.readline().split())
    graph[u].append((w,v))

dist = dijkstra(graph, K)

for i in range(1, len(dist)):
    if dist[i] == INF: print("INF")
    else: print(dist[i])