from collections import Counter

def solve(day, milk):

    ret = set()

    if day >= 4:
        return {milk[0]}

    here = day%2
    there = (day+1)%2

    for bucket in barns[here].keys():
         if barns[here][bucket] > 0:
            milk[here] -= bucket
            milk[there] += bucket
            barns[here][bucket]-= 1
            barns[there][bucket]+= 1
            
            ret |= solve(day+1, milk)
            
            milk[here] += bucket
            milk[there] -= bucket
            barns[here][bucket] += 1
            barns[there][bucket] -= 1
        
    return ret

barn0 = Counter(map(int, input().split()))
barn1 = Counter(map(int, input().split()))

barns = [barn0, barn1]

for i in range(2):
    for key in barns[i].keys():
        if key not in barns[(i+1)%2]:
            barns[(i+1)%2][key] = 0

print(len(solve(0, [1000, 1000])))