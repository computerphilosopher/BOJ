from collections import Counter

def solve(A, B, C, D):

    aplusb = [] 

    for a in A:
        for b in B:
            aplusb.append(a + b)

    counter = Counter(aplusb)
    cnt = 0

    for c in C:
        for d in D:
            if -(c+d) in counter:
                #print(-(c+d))
                cnt += counter[-(c+d)]

    return cnt

n = int(input())

A, B, C, D = ( [] for i in range(4) )

for i in range(n):
    a, b, c, d = map(int, input().split())
    A.append(a); B.append(b); C.append(c); D.append(d);

print(solve(A, B, C, D))