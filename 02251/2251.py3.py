from sys import setrecursionlimit

setrecursionlimit(10**7)

A, B, C, = 0, 1, 2

def dfs(state:tuple, visited:set):

    visited.add(state)

    ret = {state[C]} if state[A] == 0 else set()

    for giver in range(3):
        if state[giver] > 0:

            reciever = (giver + 1) % len(state)

            while ( giver != reciever):
                should_give = capacity[reciever] - state[reciever]

                after_give = state[giver]-should_give if state[giver] >= should_give else 0
                after_recive = state[giver] + state[reciever] if state[giver] + state[reciever] <= capacity[reciever] else capacity[reciever]

                if after_give == 0 or after_recive == capacity[reciever]:
                    new_state = list(state)
                    new_state[giver], new_state[reciever] = after_give, after_recive
                    new_state = tuple(new_state)

                    if new_state not in visited:
                        ret = ret | dfs(new_state, visited)
                
                reciever = (reciever + 1) % len(state)
    
    return ret

                    


capacity = tuple(map(int, input().split()))
start_state = (0, 0, capacity[len(capacity)-1])

solution = sorted(list(dfs(start_state, set())))

for s in solution:
    print(s, end = " ")