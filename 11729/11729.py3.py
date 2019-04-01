def hanoi(n, start, waypoint, destination):

    if n <= 0:
        return (0, "")
        
    prev = hanoi(n-1, start, destination, waypoint)
    cur= (1, "%d %d\n"%(start, destination))
    last = hanoi(n-1, waypoint, start, destination)

    return (prev[0] + cur[0] + last[0], prev[1] + cur[1] + last[1])


n = int(input())

ans = hanoi(n, 1, 2, 3)

for line in ans:
    print(line)