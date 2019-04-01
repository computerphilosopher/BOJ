def solve(n:int, m:int, memo:set, picked:list)->int:

    if(m == 0):

        for p in picked:
            print(p, end = " ")
        print("")


    for k in range(1, n+1):
        
        if k not in memo:
            memo.add(k)
            picked.append(k)
            solve(n, m-1, memo, picked)
            memo.remove(k)
            picked.pop()


    
n, m = map(int, input().split())

solve(n, m, set(), list())
