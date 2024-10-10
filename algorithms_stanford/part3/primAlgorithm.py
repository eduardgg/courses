import heapq

def load_graph(filename):
    f = open(filename, 'r')
    n, m = f.readline().split()
    n, m = int(n), int(m)
    edges = {}
    for i in range(m):
        a, b, w = f.readline().split()
        a, b, w = int(a), int(b), int(w)
        edges[a] = edges.get(a, []) + [(b, w)]
        edges[b] = edges.get(b, []) + [(a, w)]
    
    print(edges)
    return edges, n

def prim(edges, nodes):
    cost = 0
    MST = {i:[] for i in range(1, nodes+1)}
    left = {i for i in range(1, nodes+1)}
    left.remove(1)
    heap = []
    for e in edges[1]:
        heapq.heappush(heap, (e[1], 1, e[0]))
    while len(left) > 0:
        w, a, b = heapq.heappop(heap)
        if b in left:
            left.remove(b)
            MST[a] = MST[a] + [b]
            MST[b] = MST[b] + [a]
            cost += w
            for e in edges[b]:
                if e[0] in left:
                    heapq.heappush(heap, (e[1], b, e[0]))
    return MST, cost

def main():
    
    edges, nodes = load_graph('edges.txt')
    MST, cost = prim(edges, nodes)
    print(MST)
    print(cost)

if (__name__ == '__main__'):
	main()