from collections import deque

direction = ( (-2, -1), (-1, -2), (1, -2), (2, -1),
               (-2, 1), (-1, 2), (1, 2), (2, 1) )

def in_board(size, cur):
    r, c = cur[0], cur[1]
    return r >= 0 and c >= 0 and r < size and c < size 

def bfs(size, start, dest):
    q = deque()
    q.append(start)

    dist = dict()
    dist[start] = 0

    while q:
        here = q.popleft()

        if here == dest:
            return dist[here]
        
        for i in range(len(direction)):
            next_node = (here[0] + direction[i][0], here[1] + direction[i][1])

            if in_board(size, here) and next_node not in dist:
                q.append(next_node)
                dist[next_node] = dist[here] + 1
    
    return -1


case_count = int(input())

for t in range(case_count):
    size = int(input())
    start = tuple(map(int, input().split()))
    dest = tuple(map(int, input().split()))

    print(bfs(size, start, dest))