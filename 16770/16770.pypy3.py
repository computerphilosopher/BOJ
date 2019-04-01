def solve():
    buckets_count = 0
    using_count = 0

    time = 0

    while time <= max_end:
        if time in start_time:
            remain = buckets_count - using_count
            i = start_time[time]

            if remain < need_amount[i]:
                buckets_count += need_amount[i] - remain
            
            using_count += need_amount[i]
        
        if time in end_time:
            i = end_time[time]
            using_count -= need_amount[i]
        
        time += 1

    return buckets_count

N = int(input())
start_time, end_time, need_amount = dict(), dict(), []
max_end = -1

for i in range(N):
    s, e, n = map(int, input().split())
    start_time[s] = i; end_time[e] = i

    max_end = max(max_end, e)
    need_amount.append(n)

print(solve())