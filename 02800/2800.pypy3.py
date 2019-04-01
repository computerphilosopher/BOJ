def solve(start:str)->list:
    stack = []
    ret = []
    q = [start]

    discovered = {start}

    while len(q):

        s = q.pop(0)

        for i, ch in enumerate(s):
            if ch == '(':
                stack.append(i)

            elif ch == ')':
                left = stack.pop(len(stack)-1) 
                tmp = s[0:left] + s[left+1:i] + s[i+1:len(s)]

                if tmp not in discovered:
                    q.append(tmp)
                    discovered.add(tmp)

    discovered.remove(start)
    return sorted(list(discovered))
            

s = input()

ans = solve(s)

for line in ans:
    print(line)