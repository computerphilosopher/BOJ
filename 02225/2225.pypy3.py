def disassemble_sum(n:int, k:int)->int:

     
    if k == 0:
        return n == 0

    if (n, k) in cache:
        return cache[(n, k)]

    ret = 0

    for i in range(n+1):
        ret += disassemble_sum(n-i, k-1)

    cache[(n, k)] = ret
    return cache[(n, k)] % 1000000000

def test(n)->int:
    return n

n, k = map(int, input().split())
cache = dict()

print(disassemble_sum(n, k))
