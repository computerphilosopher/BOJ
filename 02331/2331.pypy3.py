def sequence_function(n:int, power:int)->int:

    ret = 0

    while(n):
        tmp = (n % 10) ** power
        ret += tmp
        n //= 10

    return ret
    

def sequence_without_repeat(start:int, power:int)->int:

    D = []
    num_idx_map = dict()

    current = start
    idx = 0

    while(current not in num_idx_map):
        
        num_idx_map[current] = idx

        D.append(current)

        current = sequence_function(current, power)
        idx+=1

    end_idx = num_idx_map[current]

    ''' for debugging
    print(D[0:end_idx])
    print(sorted(list(num_idx_map), key = num_idx_map.get))

    print("Duplicate", current, "at", end_idx, sequence_function(current, power))
    '''

    return D[0:end_idx]


start, power = map(int, input().split())
print(len(sequence_without_repeat(start, power)))
