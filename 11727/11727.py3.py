import sys
sys.setrecursionlimit(10**6)

def solve_recursive(n:int, cache:dict)->int:

    if n < 0:
        return 0

    if n == 0:
        return 1

    if n in cache:
        return cache[n]

    cache[n] = (solve_recursive(n-1, cache))%10007 + (2 * solve_recursive(n-2, cache)%10007)

    return cache[n] % 10007

n = int(input())

print(solve_recursive(n, dict()))
