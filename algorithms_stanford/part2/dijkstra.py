def load_graph():
    global graph, weight
    with open("dijkstraData.txt", 'r') as f:
        for line in f:
            s = line.split()
            u = int(s[0])
            for i in range(len(s)-1):
                v, w = s[i+1].split(",")
                v, w = int(v), int(w)
                graph[u] = graph.get(u,[]) + [v]
                weight[u] = weight.get(u,[]) + [w]
    return

def dijkstra(inicial):
    nodes = len(graph)
    distance = [10**6]*nodes
    distance[inicial-1] = 0
    previous = [-1]*nodes
    cua = [inicial]
    while len(cua) > 0:
        posmin = 0
        for i in range(len(cua)):
            if distance[cua[i]-1] < distance[cua[posmin]-1]:
                posmin = i
        nodemin = cua[posmin]
        cua.remove(nodemin)
        for i in range(len(graph[nodemin])):
            if distance[graph[nodemin][i]-1] > distance[nodemin-1] + weight[nodemin][i]:
                distance[graph[nodemin][i]-1] = distance[nodemin-1] + weight[nodemin][i]
                previous[graph[nodemin][i]-1] = nodemin
                cua = cua + [graph[nodemin][i]]
    print(distance)
    print(previous)
    for i in [7,37,59,82,99,115,133,165,188,197]:
        print(distance[i-1], end = ",")
    return

graph = {}
weight = {}
# print(graph)
# print(weight)
load_graph()
dijkstra(1)

# Solució "grafProvaDijkstra.txt":
# Distàncies: [0, 4, 11, 17, 9, 22, 7, 8, 11]

# Solució Assignment "dijkstraData.txt"
# Distàncies als nodes 7,37,59,82,99,115,133,165,188,197:
# 2599,2610,2947,2052,2367,2399,2029,2442,2505,3068