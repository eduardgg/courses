
# CAL ARREGLAR TEST CASES:
# graph1.txt i graph2.txt
# (resultat: cicles negatius)

from heapq import heappop, heappush

def build_graph_in(filename):
	# Aquí, tant graph com weights emmagatzemen els vèrtexos i pesos
	# (respectivament) de cada aresta d'entrada al v de l'índex.
	f = open(filename, "r")
	n, m = map(int, f.readline().split())
	graph = [[] for _ in range(n+1)]
	weights = [[] for _ in range(n+1)]
	for _ in range(m):
		u, v, w = map(int, f.readline().split())
		graph[v].append(u)
		weights[v].append(w)
	return graph, weights

def build_Johnson_graph(filename, sPath):
	# Aquí, tant graph com weights emmagatzemen els vèrtexos i pesos
	# (respectivament) de cada aresta de sortida des de v.
    f = open(filename, "r")
    n, m = map(int, f.readline().split())
    graph = [[] for _ in range(n+1)]
    weights = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v, w = map(int, f.readline().split())
        graph[u].append(v)
        # print("debug", u, v, len(sPath))
        weights[u].append(w + sPath[u] - sPath[v])
    return graph, weights

def bellmanFord(graph, weights, source):
	inf = 10**12
	A = [inf]*len(graph)
	A[source] = 0
	iteracions = 0
	# a és la còpia de A
	# Com que en cada iteració només es necessiten els valors de la
	# iteració anterior, emmagatzemem una còpia en "a" i consumim
	# O(n) d'espai en lloc de O(n^2).
	# La inicialització només requereix ser diferent de "A":
	a = [inf]*len(graph)
	while iteracions <= len(graph) and a != A:
		a = [e for e in A]
		for v in range(1, len(graph)):
			for i in range(len(graph[v])):
				A[v] = min(A[v], a[graph[v][i]] + weights[v][i])	
		iteracions += 1		
	if a != A:
		print("Negative Cycle found")
		return
	return A


def dijkstra(graph, weights, inicial):

    # Implementació eficient usant Dijkstra
    # (ara sí que es nota molt la diferència!)
    distance = [10**6]*(len(graph))
    distance[inicial] = 0
    heap = [(distance[inicial], inicial)]
    while heap:
        mi, node = heappop(heap) # mi = distance[node]
        for i in range(len(graph[node])):
            if distance[graph[node][i]] > distance[node] + weights[node][i]:
                distance[graph[node][i]] = distance[node] + weights[node][i]
                heappush(heap, (distance[graph[node][i]], graph[node][i]))
                
    """
    # Implementació ineficient de Dijkstra!
    # (Cal repetir fent ús de heaps)
    distance = [10**6]*(len(graph))
    distance[inicial-1] = 0
    cua = [inicial]
    while len(cua) > 0:
        posmin = 0
        for i in range(len(cua)):
            if distance[cua[i]-1] < distance[cua[posmin]-1]:
                posmin = i
        nodemin = cua[posmin]
        cua.remove(nodemin)
        for i in range(len(graph[nodemin])):
            if distance[graph[nodemin][i]-1] > distance[nodemin-1] + weights[nodemin][i]:
                distance[graph[nodemin][i]-1] = distance[nodemin-1] + weights[nodemin][i]
                cua = cua + [graph[nodemin][i]]
    """

    return distance
    
def main():

    data = 'graph3.txt'
    print('Building graph from file...')
    graph, weights = build_graph_in(data)
    
    print('Computing shortest paths through Bellman-Ford...')
    # Aquí la source és 0, ja que és el vèrtex "inventat".
    graph = [[0] for _ in range(len(graph))]
    weights = [[0] for _ in range(len(graph))]
    shortestPath = bellmanFord(graph, weights, 0)
    # print(shortestPath)
    # print()

    print('Building Johnson Graph...')
    # Construïm el nou graf. Aquest cop, segons les arestes i
    # pesos que surten de cada vèrtex. A més, els weights es
    # transformen a positius segons l'algorisme de Johnson,
    # a través del camí mínim trobat per Bellman - Ford.
    graph, weights = build_Johnson_graph(data, shortestPath)
    
    print('Computing real minimum paths through Dijkstra...')
    # I finalment fem Dijkstra amb cadascun dels vèrtexos, i
    # reportem el mínim de les longituds mínimes entre vèrtexos:
    minPath = 10**12
    for v in range(1, len(graph)):
        d = dijkstra(graph, weights, v)
        for i in range(len(d)):
            d[i] += (shortestPath[i] - shortestPath[v])
        # Si volem reportar totes les longituds des de cada v:
        # print(d)
        mD = min(d)
        print(v, ": ", mD)
        minPath = min(minPath, mD)
    
    print('And we got it!:')
    print(minPath)

    # Els resultats són:
    # graph1: Negative Cycle
    # graph2: Negative Cycle
    # graph3: -19


if (__name__ == '__main__'):
	main()