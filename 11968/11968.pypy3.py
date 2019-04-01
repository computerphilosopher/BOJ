def can_win(elsie_card):
    return bessie_max >= elsie_card

def smallest_win(small_winner, elsie_card):
    for i in range(small_winner, len(bessie)):
        if bessie[i] > elsie_card:
            return i
    
    return small_winner

def solve():
    point = 0
    small_winner = 0

    for i in range(len(elsie)):
        if can_win(elsie[i]):
            small_winner = smallest_win(small_winner, elsie[i]) + 1
            point += 1

            if small_winner >= len(bessie): break

        else: break

    return point

N = int(input())

elsie = tuple(sorted([int(input()) for _ in range(N)]))
bessie = tuple(sorted(list((set([i for i in range(1, 2*N+1)]) - set(elsie)))))

bessie_max = bessie[-1]

print(solve())