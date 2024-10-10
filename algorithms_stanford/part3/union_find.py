import random

class UnionFind(object):

    def __init__(self, name = None):
        self.rank = 0
        self.parent = self
        self.name = name

    # Vigilar amb això (treure si cal):
    def __lt__(self, other):
        if self.name <= other.name:
            return True
        return False
    
    def find(self):
        # Cost: O(Log(n))
        while self.parent != self:
            self = self.parent
        return self

    def lazyUnion(self, other):
        # Cost: O(1)
        s = self.find()
        o = other.find()
        if s == o:
            return
        if s.rank >= o.rank:
            o.parent = s
            if s.rank == o.rank:
                s.rank += 1
            return
        s.parent = o
        return


""""
n = 100
unions = 100
nodes = []
counter = 0
for i in range(n):
    nodes.append(UnionFind("Node" + str(i)))

for j in range(unions):
    ind1 = random.randrange(n)
    ind2 = random.randrange(n)
    nodes[ind1].lazyUnion(nodes[ind2])
    print(ind1, ind2)

leaders = set()
tamanys = dict()
for node in nodes:
    print(node.find().name)
    tamanys[node.find().name] = tamanys.get(node.find().name, 0) + 1 
    if node.parent == node:
        leaders.add(node.name)

print(leaders)
print(tamanys)
"""