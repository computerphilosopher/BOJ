import sys
sys.setrecursionlimit(10**7)

class disjoint_set:

    def __init__(self):
        self.parent = dict()
        self.rank = dict()
        self.size = dict()

    def find(self, u):
        if u not in self.parent:
            self.parent[u] = u
            self.rank[u] = 1
            self.size[u] = 1
            return u
        
        if u == self.parent[u]:
            return u
        
        self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def merge(self, u, v):

        uparent = self.find(u)
        vparent = self.find(v)

        if uparent == vparent:
            return

        if self.rank[uparent] < self.rank[vparent]:
            uparent, vparent = vparent, uparent

        if self.rank[uparent] == self.rank[vparent]:
            self.rank[uparent] += 1

        self.parent[vparent] = uparent
        self.size[uparent] += self.size[vparent]

    
tc = int(input())

for t in range(tc):
    f = int(input())
    ds = disjoint_set()

    for i in range(f):
        u, v = input().split()
        ds.merge(u, v)
        uparent = ds.find(u); vparent= ds.find(v)

        if ds.rank[uparent] > ds.rank[vparent]:
            print(ds.size[uparent])
        else:
            print(ds.size[vparent])
  