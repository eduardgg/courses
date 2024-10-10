
from union_find import UnionFind
    
def load_graph(filename):
    f = open(filename, 'r')
    n, m = f.readline().split()
    n, m = int(n), int(m)
    edges = []
    for i in range(m):
        a, b, w = f.readline().split()
        edges += [(int(w), int(a), int(b))]
    edges.sort()
    return edges, n

def kruskal(V, MST, n, edges):
    cost = 0
    comps = n
    i = 0
    while comps > 1 and i < len(edges):
        e = edges[i]
        i += 1
        if V[e[1]-1].find() == V[e[2]-1].find():
            continue
        V[e[1]-1].lazyUnion(V[e[2]-1])
        # print(e[1], e[2])
        MST[e[1]] = MST.get(e[1]) + [e[2]]
        MST[e[2]] = MST.get(e[2]) + [e[1]]
        cost += e[0]
        comps -= 1
    return cost


def main():
    
    edges, nodes = load_graph('edges.txt')
    MST = {i:[] for i in range(1,nodes+1)}
    V = [UnionFind(i) for i in range(nodes)]
    
    costMST = kruskal(V, MST, nodes, edges)
    print(MST)
    print(costMST)

    # Solució per a "edges.txt":
    # Cost MST = -3612829

if (__name__ == '__main__'):
	main()