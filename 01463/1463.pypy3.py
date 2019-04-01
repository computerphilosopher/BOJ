import collections

def bfs(start:int)->int:

    dist = {start:0}
    q = collections.deque()
    q.append(start)

    while q:
        here = q.popleft()

        if here == 1:
            return dist[1]
        
        if here % 3 == 0 and here//3 not in dist:
            q.append(here//3)
            dist[here//3] = dist[here] + 1
            
        if here % 2 == 0 and here//2 not in dist:
            q.append(here//2)
            dist[here//2] = dist[here] + 1

        if here-1 not in dist:
            q.append(here-1)
            dist[here-1] = dist[here] + 1

    return dist[1]


n = int(input())
print(bfs(n))