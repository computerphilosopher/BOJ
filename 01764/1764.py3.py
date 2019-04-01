n, m = map(int, input().split())

no_hear = set()

for i in range(n):
    name = input()
    no_hear.add(name)

no_see = set()

for i in range(m):
    name = input()
    no_see.add(name)

answer = no_hear & no_see

print(len(answer))

toprint = sorted(list(answer))

for l in toprint:
    print(l)


