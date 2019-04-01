from sys import stdin
from sys import stdout
from sys import setrecursionlimit
setrecursionlimit(10**7)

cache = dict()
all_case = set()

def judge(first, second):

    winner = max(first,second)
    loser = min(first,second)
    remain = round_count - winner

    if winner == second:
        if winner > loser + remain + 1:
            return 0

    elif winner > loser + remain + 2:
        return 0
    
    return 1


round_count = int(stdin.readline())
case_count = int(stdin.readline())

for _ in range(case_count):
    m, n = map(int, stdin.readline().split())
    print(judge(m, n))