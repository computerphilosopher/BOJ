n = int(input())

participant = dict()

for i in range(n):
    name = input()

    if name in participant:
        participant[name] += 1
    else:
        participant[name] = 1

complete = dict()

for i in range(n-1):

    name = input()

    if name in complete:
        complete[name] += 1
    else:
        complete[name] = 1


for name in participant:
    if name not in complete or participant[name] != complete[name]:
        print(name)
        break
 