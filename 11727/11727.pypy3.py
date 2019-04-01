import sys
sys.setrecursionlimit(10**6)

MOD = 10007

def solve_recursive(n:int, cache:dict)->int:

    if n < 0:
        return 0

    if n == 0:
        return 1

    if n in cache:
        return cache[n]

    cache[n] = (solve_recursive(n-1, cache))%MOD + (2 * solve_recursive(n-2, cache)%MOD)

    return cache[n] % MOD

def solve_iterative(n:int):

    cache = dict()

    cache[0] = 1
    cache[1] = 1

    for i in range(2, n+1):
        cache[i] = (cache[i-1] + 2 * (cache[i-2]))%MOD

    return cache[n]%MOD

n = int(input())

#print(solve_recursive(n, dict()))
print(solve_iterative(n))
