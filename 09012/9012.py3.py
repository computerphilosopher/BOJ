import queue

def is_vps(line):

    stack = queue.LifoQueue()

    for ch in line:
        if(ch == '('):
            stack.put(ch)
        else:
            if stack.empty():
                return "NO"
            tos = stack.get()

    if stack.empty():
        return "YES"
    
    return "NO";

t = int(input())

for i in range(t):
    line = input()
    print(is_vps(line))
    

