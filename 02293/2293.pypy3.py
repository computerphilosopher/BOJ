from sys import setrecursionlimit
setrecursionlimit(10**7)

def solve(money, i):
    
    if money <= 0:
        return int(money == 0)
    if i >= N:
        return 0
    if cache[money][i] != -1:
        return cache[money][i]

    ret = 0
    change = money

    while change>= 0:
        ret += solve(change,i+1)
        change-= coins[i]
    
    cache[money][i] = ret
    return ret
    
N, K = map(int, input().split())
cache = [ [-1]*N for _ in range(K+1) ]
coins = tuple(int(input()) for i in range(N))

print(solve(K,0))