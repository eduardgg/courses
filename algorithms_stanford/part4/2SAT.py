
# Recurs interessant sobre l'algorisme per a 2-SAT (O(V+E)):
# https://www.geeksforgeeks.org/2-satisfiability-2-sat-problem/

def build_graph(filename):
    f = open(filename, "r")
    n = int(f.readline())
    # n variables, n clàusules
    g = {}
    for _ in range(n):
        x, y = f.readline().split()
        x, y = int(x), int(y)
        g[-x] = g.get(-x, []) + [y]
        g[-y] = g.get(-y, []) + [x]
    return g

def graph_reverse(g):
    grev = {}
    for i in g.keys():
        for j in g[i]:
            grev[j] = grev.get(j, []) + [i]
    return grev

def dfs1(g):
    stack = []
    ordering = []
    explored = {}
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

def dfs2(g, ordering):
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



def main():
    print('Building graph from file...')
    g = build_graph('2sat1.txt')
    gRev = graph_reverse(g)
    # print(g)
    # print(gRev)

    # KOSARAJU'S ALGORITHM to find SSC:

    # PAS 1: Trobar l'ordenament "màgic":
    print('Finding Kosaraju ordering...')
    ordering = dfs1(gRev)
    # print(ordering)

    # PAS 2: Trobar els líders de les SCCs:
    print('Computing leaders of SCCs...')
    leaders = dfs2(g, ordering)
    # print(leaders)
    # cjt = set([leaders[i] for i in leaders.keys()])
    # print(cjt)
    # print(len(cjt))

    # PAS 3: Trobar les SCCs:
    print('Finding Connected Components...')
    SCC = {}
    SAT = True
    for i in leaders.keys():
        comps = SCC.get(leaders[i], set())
        if -i in comps:
            SAT = False
            break
        comps.add(i)
        SCC[leaders[i]] = comps

    # print(SCC)
    if SAT:
        print("The problem is satisfiable")
    else:
        print("The problem is NOT satisfiable")

    # 2sat1.txt -> SATISFIABLE
    # 2sat2.txt -> NOT SATISFIABLE
    # 2sat3.txt -> SATISFIABLE
    # 2sat4.txt -> SATISFIABLE
    # 2sat5.txt -> NOT SATISFIABLE
    # 2sat6.txt -> NOT SATISFIABLE


if (__name__ == '__main__'):
	main()