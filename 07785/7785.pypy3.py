NAME = 0
ACTION = 1

n = int(input())
people_in_company = set() 

for i in range(n):
 
    whole_input = input().split()

    if whole_input[ACTION] == "enter":
        people_in_company.add(whole_input[NAME])

    else:
        people_in_company.remove(whole_input[NAME])


solution = sorted(list(people_in_company), reverse = True)

for s in solution:
    print(s)
