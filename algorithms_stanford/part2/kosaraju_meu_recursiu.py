
def load_graph():
    g = {}
    with open("graf2.txt", 'r') as f:
        for line in f:
            s,t = line.split()
            s,t = int(s),int(t)
            dest_nodes = g.get(s, set())
            dest_nodes.add(t)
            g[s] = dest_nodes
    return g

def graph_reverse(g):
    grev = {}
    for i in g.keys():
        for j in g[i]:
            if j not in grev.keys():
                grev[j] = [i]
                continue
            grev[j] += [i]
    return grev

def dfs1(g):
    for i in range(nodes):
        if explored[i] == 0:
            dfs2(g,i+1)
    return

def dfs2(g,i):
    global t
    explored[i-1] = 1
    for j in g.get(i, set()):
        if explored[j-1] == 0:
            dfs2(g,j)
    t += 1
    ordering[t-1] = i
    return

def dfs3(g):
    global source
    for i in ordering:
        if explored[i-1] == 0:
            source = i
            dfs4(g,i)
    return

def dfs4(g,i):
    global source
    explored[i-1] = 1
    leader[i-1] = source
    for j in g.get(i, set()):
        if explored[j-1] == 0:
            dfs4(g,j)
    return


g = load_graph()
nodes = max(max([max(g[i]) for i in g.keys()]),max(g.keys()))
# print(g)
print("Number of Nodes:")
print(nodes)

grev = graph_reverse(g)
t = 0
source = None
ordering = [0]*nodes
explored = [0]*nodes
dfs1(grev)

print("Ordering Found: ")
ordering = ordering[::-1]
# print(ordering)

source = None
explored = [0]*nodes
leader = [0]*nodes
dfs3(g)
# print(leader)

print("Leaders of SCC:")
print(set(leader))
print("Number of SCC:")
print(len(set(leader)))