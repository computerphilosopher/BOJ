import collections

def solution(arrangement):
    
    d = collections.deque()
    ret = 0
    
    for i, ch in enumerate(arrangement):
        if ch == '(':
            d.append(ch)
        elif arrangement[i-1] == '(':
            d.pop()
            ret += len(d)
        else:
            ret += 1
            d.pop()
            
    return ret 

print(solution(input()))