
def build_graph(filename):
	f = open(filename, "r")
	n, m = map(int, f.readline().split())
	graph = [[] for _ in range(n+1)]
	# Aquí, emmagatzem arestes: (node destí, weight)
	for _ in range(m):
		u, v, w = map(int, f.readline().split())
		graph[v].append((u, w))
	return graph

def bellmanFord(graph, source):
	inf = 10**12
	n = len(graph)
	A = [inf]*n
	A[source] = 0
	iteracions = 0
	# a és la còpia de A
	# Com que en cada iteració només es necessiten els valors de la
	# iteració anterior, emmagatzemem una còpia en "a" i consumim
	# O(n) d'espai en lloc de O(n^2).
	# La inicialització només requereix ser diferent de "A":
	a = [inf]*n
	while iteracions < n and a != A:
		a = [e for e in A]
		for v in range(1, n):
			for (u, w) in graph[v]:
				A[v] = min(A[v], a[u] + w)	
		iteracions += 1		
	if a != A:
		print("Negative Cycle found")
		return
	return A

def main():
	print('Building graph from file...')
	graph = build_graph('graph3.txt')
	print('Computing shortest path...')
	print(bellmanFord(graph, 1))

if (__name__ == '__main__'):
	main()