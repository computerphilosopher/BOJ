def solve(word:str)->bool:

    stack = []

    for ch in word:

        if not stack:
            stack.append(ch)

        elif stack[len(stack)-1] == ch:
            stack.pop()

        else:
            stack.append(ch)

    if stack:
        return False

    return True

        

n = int(input())
solution = 0

for t in range(n):
    word = input()
    solution += solve(word)

print(solution)
