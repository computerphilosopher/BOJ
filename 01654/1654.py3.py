from sys import setrecursionlimit
setrecursionlimit(10**7)


def bin_search(lines, n, low, high):

    if low > high:
        return -float ('inf')

    divide_len = (low + high) // 2
    parts_count = 0

    for line in lines:
        cur_parts = line // divide_len
        parts_count += cur_parts

    if parts_count < n:
        return bin_search(lines, n, low,divide_len-1)

    return max(divide_len, bin_search(lines, n, divide_len+1,high))


k, n = map(int, input().split())

lines = []

high = -float('inf')

for i in range(k):
    tmp = int(input())
    lines.append(tmp)

    high = max(high, tmp)

print(bin_search(lines, n, 1, high))