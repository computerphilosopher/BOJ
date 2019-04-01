import queue

height, start, dest, up, down = map(int, input().split())

q = queue.Queue()
q.put(start)

dist = {}
dist[start] = 0

while not q.empty() :
    here = q.get()
    d = dist[here]

    if here+up <= height and here+up not in dist:
        q.put(here+up)
        dist[here+up] = d + 1

    if here-down > 0 and here-down not in dist:
        q.put(here-down)
        dist[here-down] = d + 1


if dest in dist:
    print(dist[dest])

else:
    print("use the stairs")





