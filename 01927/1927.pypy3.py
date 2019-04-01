import heapq
from sys import stdin

n = int(stdin.readline())
pq = []

for i in range(n):
    command = int(stdin.readline()) 

    if command == 0:
        if pq:
            print(heapq.heappop(pq))
        else:
            print(0)
    
    else:
        heapq.heappush(pq, command)