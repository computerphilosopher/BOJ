from sys import setrecursionlimit
setrecursionlimit(10**7)

directions = ( (-1, 0), (1, 0), (0, -1), (0, 1) )

def in_board(here):
    r, c = here[0], here[1]

    return r >= 0 and c >= 0 and r < n and c < n 

def dfs(here, mark, visited, board):

    r, c= here[0], here[1]
    board[r][c] = mark
    visited.add(here)

    ret = [here]

    for d in directions:
        there = (r + d[0], c + d[1])
        nr, nc = there[0], there[1]

        if in_board(there) and there not in visited:
            #print(here, there, left, right, abs(nations[r][c] - nations[nr][nc]))
            if left <= abs(nations[r][c] - nations[nr][nc]) <= right:
                ret += dfs(there, mark, visited, board)

    return ret

def mark_alliance():
    board = [ [-1] * n for _ in range(n)]
    mark = 0
    visited = set()
    alliances = []

    for i in range(n):
        for j in range(n):
            if (i, j) not in visited:
                alliances.append(dfs((i,j), mark, visited, board))
                mark += 1
    return alliances


def need_fix(alliances):
    max_len = max(len(alliance) for alliance in alliances)
    return max_len != 1

def fix_population(alliances):

    populations = [0] * len(alliances)
    lens = [0] * len(alliances)

    for i, alliance in enumerate(alliances):
        lens[i] += len(alliance)

        for member in alliance:
            r, c= member[0], member[1]
            populations[i] += nations[r][c]

    for i, alliance in enumerate(alliances):

        population, length = populations[i], lens[i]

        for member in alliance:
            r, c= member[0], member[1]
            nations[r][c] = population // length


def solve():
    count = 0

    while True:
        alliances = mark_alliance()
        if not need_fix(alliances): break
        fix_population(alliances)
        count += 1

    return count

n, left, right = map(int, input().split())

nations = []

for i in range(n):
    line = list(map(int, input().split()))
    nations.append(line)

print(solve())