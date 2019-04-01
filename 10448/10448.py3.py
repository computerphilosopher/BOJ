def trinum_list():
    
    ret = []
    for i in range(1, 1001):
        ret.append(i*(i+1)//2)
         
    return ret
        

def solve(trinum_list:list, n:int, depth:int)->bool:
    
   if(depth == 3):
       return n == 0 

   ret = False
   
   for num in trinum_list:
       if solve(trinum_list, n-num, depth+1):
           return True
       if num > n:
           return False

   return False



t = int(input())
trinum = trinum_list()

for i in range(t):
    n = int(input())
    print(int(solve(trinum, n, 0)))


