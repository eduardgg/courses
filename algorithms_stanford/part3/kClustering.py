
from union_find import UnionFind
    
def load_graph(filename):
    f = open(filename, 'r')
    n = int(f.readline())
    edges = []
    m = n*(n-1)//2
    for i in range(m):
        a, b, w = f.readline().split()
        edges += [(int(w), int(a), int(b))]
    edges.sort()
    # print(edges)
    return edges, n

def kruskal(V, clusters, n, edges):
    comps = n
    i = 0
    while comps >= clusters and i < len(edges):
        e = edges[i]
        i += 1
        # print(e[1], e[2])
        if V[e[1]-1].find() == V[e[2]-1].find():
            continue
        V[e[1]-1].lazyUnion(V[e[2]-1])
        comps -= 1
        # El màxim spacing és el pes de l'edge que ha fet descendre
        # el número de components per sota del nombre de clusters,
        # i per tant ha acabat el bucle.
    # print(comps, e)
    return e[0]


def main():
    
    clusters = 4
    edges, nodes = load_graph('clustering1.txt')
    V = [UnionFind(i) for i in range(nodes)]
    
    maxSpacing = kruskal(V, clusters, nodes, edges)
    print(maxSpacing)

    # Solució per a "clustering1.txt":
    # 106




if (__name__ == '__main__'):
	main()