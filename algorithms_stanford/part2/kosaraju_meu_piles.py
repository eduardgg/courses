
def load_graph(filename):
    g = {}
    with open(filename, 'r') as f:
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
            grev[j] = grev.get(j, []) + [i]
    return grev

def dfs1(g):
    ordering = []
    explored = {}
    stack = []
    for i in g.keys():
        if not explored.get(i, 0):
            stack.append(i)
            while len(stack) > 0:
                k = stack.pop()
                explored[k] = 1
                for j in g.get(k, set()):
                    if not explored.get(j, 0):
                        stack.append(j)
                ordering += [k]
    ordering = ordering[::-1]
    return ordering

def dfs2(g):
    source = None
    explored = {}
    leaders = {}
    stack = []
    for i in ordering:
        if not explored.get(i, 0):
            source = i
            stack.append(i)
            while len(stack) > 0:
                k = stack.pop()
                explored[k] = 1
                leaders[k] = source
                for j in g.get(k, set()):
                    if not explored.get(j, 0):
                        stack.append(j)
    return leaders



g = load_graph("sccData.txt")
nodes = max(max([max(g[i]) for i in g.keys()]),max(g.keys()))
# print(g)
print("Number of Nodes:")
print(nodes)

# Primer pas:
# Trobar l'ordenament "màgic"
gRev = graph_reverse(g)
ordering = dfs1(gRev)
print("Ordering found: ")
# print(ordering)

# Segon pas:
# Fer un DFS segons l'ordenament trobat:
leaders = dfs2(g)
# print("Leaders found:")
# print(leaders)

print("Number of SCC:")
# Tercer pas:
# Trobem els tamanys de les SCC:
sizes = {}
for i in leaders.keys():
    sizes[leaders[i]] = sizes.get(leaders[i], 0) + 1
print("Sizes of all SCC:")
# print(sizes)

# Mostrem els tamanys de les 5 SCC més grans:
max5sizes = [0,0,0,0,0]
for k in sizes.keys():
    if sizes[k] > max5sizes[0]:
        max5sizes[0] = sizes[k]
        max5sizes.sort()
print(max5sizes[::-1])

# Solució per a "sccData.txt"
# Total de SCCs: 341508
# 5 tamanys més grans:
# 434821, 968, 459, 313, 211