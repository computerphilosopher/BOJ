import sys
sys.setrecursionlimit(10**6)

def fib(n:int)->int:

    if n == 0:
        return 1, 0
    
    if n == 1:
        return 0, 1

    if n in cache:
        return cache[n]

    cache[n] = (fib(n-1)[0] + fib(n-2)[0], fib(n-1)[1] + fib(n-2)[1])

    return cache[n]

T = int(input())

for t in range(T):
    n = int(input())
    cache = {}

    print("%d %d"%(fib(n)[0], fib(n)[1]))
