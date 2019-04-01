def solve(capacity, amount):

    pour_count = 0
    idx = 0

    while pour_count < 100:
        a, b = idx, (idx+1)%3  

        if amount[a] + amount[b] <= capacity[b]:
            amount[b] = amount[a] + amount[b]
            amount[a] = 0

        else:
            amount[a] -= capacity[b] - amount[b]
            amount[b] = capacity[b]
        idx = b
        pour_count += 1

    return amount


capacity = []
amount = []

for i in range(3):
    c, a = map(int, input().split())
    capacity.append(c)
    amount.append(a)

buckets = solve(capacity,amount)

for bucket in buckets:
    print(bucket)