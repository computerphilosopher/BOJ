import sys

n = int(sys.stdin.readline())

for i in range(n):
    a, b = map(int, input().split(','))
    print(a+b)

