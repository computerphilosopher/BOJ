import sys
sys.setrecursionlimit(10**7)

class disjoint_set:

    def __init__(self, n:int):
        self.parent = []
        self.rank= [1] * n

        for i in range(n):
            self.parent.append(i)

    def find(self, u:int):
        
        if u == self.parent[u]:
            return u

        self.parent[u] = self.find(self.parent[u])

        return self.parent[u]

    def merge(self, u, v):

        uparent = self.find(u)
        vparent = self.find(v)

        if uparent == vparent:
            return
        
        if self.rank[uparent] > self.rank[vparent]:
            uparent, vparent = vparent, uparent

        if self.rank[uparent] == self.rank[vparent]:
            self.rank[vparent]+=1

        self.parent[uparent] = vparent;

 
n, m = map(int, input().split())

ds = disjoint_set(n+1)

for t in range(m):
    command = list(map(int, input().split()))

    if command[0] == 0:
        ds.merge(command[1], command[2])
    else:
        a = ds.find(command[1])
        b = ds.find(command[2])

        if a == b:
            print("YES")
        else:
            print("NO")
