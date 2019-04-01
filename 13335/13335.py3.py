from collections import deque

def solution(bridge_length, weight, truck_weights):

    q = deque(truck_weights) 
    s = 0

    time= 0

    bridge = deque() 

    leaved = 0

    while leaved < len(truck_weights):

        if bridge and time - bridge[0][1] >= bridge_length:
            s -= bridge.popleft()[0]
            leaved += 1

        if q and s + q[0] <= weight and len(bridge) < bridge_length:
            w = q.popleft() 
            bridge.append((w,time))
            s += w 
      
        time += 1 

    return time

truck_count, bridge_length, weight = map(int, input().split())

truck_weights = list(map(int, input().split()))

print(solution(bridge_length, weight, truck_weights))