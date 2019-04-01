from sys import setrecursionlimit
setrecursionlimit(10**7)

cache = dict()

def solve(l, r):
    if l >= len(left_cards) or r >= len(right_cards):
        return 0

    if (l, r) in cache:
        return cache[(l, r)]

    if right_cards[r] < left_cards[l]:
        cache[(l, r)] = right_cards[r] + solve(l, r+1)
    else: 
         cache[(l, r)]= max(solve(l+1, r), solve(l+1, r+1))

    return cache[(l, r)]


n = int(input())
left_cards = tuple(map(int, input().split()))
right_cards = tuple(map(int, input().split()))

print(solve(0, 0))