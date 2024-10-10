
from matplotlib import pyplot
import math
import datetime

def build_graph(filename):
    f = open(filename, "r")
    n = int(f.readline())
    xs = []
    ys = []
    for i in range(n):
        x, y = f.readline().split()
        x, y = float(x), float(y)
        xs += [x]
        ys += [y]
    return n, xs, ys

def draw_plot(xs, ys):
    for i in range(len(xs)):
        pyplot.plot(xs[i], ys[i], marker = "o", color = "red")
        pyplot.annotate(str(i+1), (xs[i],ys[i]))
    # Per intuir millor les distàncies euclidianes, cal tenir la
    # mateixa escala pels eixos x i y. Per això definim un marge
    # suficient per encabir tots els punts, igual pels dos eixos.
    # CANVIAR-HO SI FEM SERVIR UNA ALTRA MOSTRA
    pyplot.xlim(xmin=20000,xmax=28000)
    pyplot.ylim(ymin=9500,ymax=17500)
    pyplot.show()

def drawPath(v, xs, ys):
    for i in range(len(xs)):
        pyplot.plot(xs[i], ys[i], marker = "o", color = "red")
        pyplot.annotate(str(i+1), (xs[i],ys[i]))
    pyplot.xlim(xmin=20000,xmax=28000)
    pyplot.ylim(ymin=9500,ymax=17500)
    d = 0
    xx = [xs[v[0]-1]]
    yy = [ys[v[0]-1]]
    for i in range(len(v)-1):
        d += dist(xs,ys,v[i+1],v[i])
        xx += [xs[v[i+1]-1]]
        yy += [ys[v[i+1]-1]]
    pyplot.plot(xx, yy, marker = "o", color = "black")
    pyplot.show()
    return d

def dist(xs, ys, j, k):
    return math.sqrt((xs[j-1]-xs[k-1])**2 + (ys[j-1]-ys[k-1])**2)

def codeSet(set):
    code = 0
    # Assumim que els elements del conjunt tenen índexos 
    # 1,2,3,...,n, i trobem el nombre binari equivalent.
    for e in set:
        code += 2**(e-1)
    return code

def binaryWords(V, s, m, n):
    if m == 0 and n == 0:
        V += [s]
    if m > 0:
        binaryWords(V, s + "1", m-1, n-1)
    if m < n:
        binaryWords(V, s + "0", m, n-1)
    return

def tspAlgorithm(n, xs, ys):

    A = {(codeSet({1}),1): 0}
    INF = 10**12
    # Pels altres conjunts S: A[S,1] = INFINIT
    # Però només donarem el valor més endavant, quan calgui
    
    for m in range(2,n+1):
        print("m =", m, "of", n, "     ", datetime.datetime.now())
        V = []
        binaryWords(V, "", m-1, n-1)
        for s in V:
            S = {1}
            for i in range(len(s)):
                if s[i] == "1":
                    S.add(i+2)
            for j in S:
                if j != 1:
                    SS = {e for e in S}
                    SS.remove(j)
                    if SS != {1}:
                        A[(codeSet(SS),1)] = INF
                    A[(codeSet(S),j)] = min([A[codeSet(SS),k] + dist(xs, ys, j, k) for k in SS])

    full = {i+1 for i in range(n)}
    minPath = INF
    for j in range(2, n+1):
        if A[(codeSet(full), j)] + dist(xs, ys, j, 1) < minPath:
            minPath = A[(codeSet(full), j)] + dist(xs, ys, j, 1)
            ultim = j

    # Ara imprimim el camí òptim:
    path = []
    copia = ultim
    while len(full) > 0:
        path += [ultim]
        full.remove(ultim)
        minim = INF
        for j in full:
            if minim > A[(codeSet(full), j)] + dist(xs, ys, j, ultim):
                minim = A[(codeSet(full), j)] + dist(xs, ys, j, ultim)
                posmin = j
        ultim = posmin
    path += [copia]
    
    xx = []
    yy = []
    for i in path:
        xx += [xs[i-1]]
        yy += [ys[i-1]]

    # Dibuixem el camí trobat:
    # pyplot.plot(xx, yy, marker = "o", color = "red")
    # pyplot.show()

    print(path)
    return minPath

def main():
    print('Building graph from file...')
    n, xs, ys = build_graph('tspData.txt')

    # print('Drawing plot...')
    draw_plot(xs, ys)
    
    print('Computing shortest path...')
    # print(tspAlgorithm(n, xs, ys))
    # L'algorisme no acaba per n = 25, però ho resol molt
    # fàcilment fins n = 15, per tant ho resolem per dos
    # cicles diferents i els enganxem "a ull":
    s1 = tspAlgorithm(13, xs[:13], ys[:13])
    s2 = tspAlgorithm(14, xs[11:], ys[11:])
    resultat = s1 + s2 - 2 * dist(xs, ys, 12, 13)
    print(resultat)
    # Longitud del Shortest Path: 26442.730308954753
    sPath = [15,19,18,22,23,21,17,20,25,24,16,14,13,9,7,3,4,8,5,1,2,6,10,11,12,15]
    l = drawPath(sPath, xs, ys)

if (__name__ == '__main__'):
	main()