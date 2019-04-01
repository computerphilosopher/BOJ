def solve(left, right):

    if left == right:
        return 0

    nl = left // 2 
    nr = right // 2 

    if(left%2):
        nl += 1
    if(right%2):
        nr += 1

    return 1 + solve(nl, nr)


n, left, right = map(int, input().split())

if(left > right):
    left, right = right, left

print(solve(left, right))

