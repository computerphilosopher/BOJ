from sys import setrecursionlimit
setrecursionlimit(10**7)

class disjoint_set:

    def __init__(self, n:int):
        self.parent = [0] * n 
        self.rank = [1] * n
        self.enemy = [-1] * n

        for i in range(n):
            self.parent[i] = i

    def find(self, u:int)->int:
        if self.parent[u] == u:
            return u

        self.parent[u] = self.find(self.parent[u])

        return self.parent[u]

    def merge(self, u:int, v:int):

        if u == -1 or v == -1:
            return max(u, v)

        large, small = self.find(u), self.find(v)

        if large == small:
            return large

        if self.rank[large] < self.rank[small]:
            large, small = small, large

        if self.rank[large] == self.rank[small]:
            self.rank[large]+=1

        self.parent[small] = large

        return large

    def ack(self, u:int, v:int)->bool:
         
        u = self.find(u)
        v = self.find(v)

        if self.enemy[u] == v:
            return False

        merged_parent = self.merge(u, v)
        merged_enemy = self.merge(self.enemy[u], self.enemy[v])

        self.enemy[merged_parent] = merged_enemy

        if merged_enemy != -1:
            self.enemy[merged_enemy] = merged_parent

        return True


    def dis(self, u:int, v:int)->bool:

        u = self.find(u)
        v = self.find(v)

        if u == v:
            return False

        ufriends = self.merge(u, self.enemy[v])
        vfriends = self.merge(v, self.enemy[u])

        self.enemy[ufriends] = vfriends
        self.enemy[vfriends] = ufriends

        return True
        

friends, questions = map(int, input().split())
dset = disjoint_set(friends)
contradiction = False

for i in range(questions):
    u, v, judge = input().split()
    u, v = int(u)-1, int(v)-1

    if judge == 'T':
        if not dset.ack(u, v):
            contradiction = True
            print(i)
            break
    
    elif judge == 'L':
        if not dset.dis(u, v):
            contradiction = True
            print(i)
            break

if not contradiction:
    print(questions)
