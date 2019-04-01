def solve(n:int, m:int, memo:set, picked:list)->int:

    if(m <= 0):
        for p in picked:
            print(p, end = " ")
        print("")
        return 

    for k in range(1, n+1):
        picked.append(k)
        solve(n, m-1, memo, picked)
        picked.pop()

    
n, m = map(int, input().split())

solve(n, m, set(), list())
