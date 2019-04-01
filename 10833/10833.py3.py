def solve(L):

    ret = 0

    for element in L:
        ret += element[1] % element[0] 

    return ret


n = int(input())

L = []

for i in range(n):
    students, apples = map(int, input().split())
    L.append((students, apples))

print(solve(L))