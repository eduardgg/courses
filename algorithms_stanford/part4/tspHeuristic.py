
from matplotlib import pyplot
import math

def build_graph(filename):
    f = open(filename, "r")
    n = int(f.readline())
    ns = []
    xs = []
    ys = []
    # Podem canviar aquest rang si volem més o menys dades
    # Per defecte, posem n (nombre total de punts a l'arxiu)
    for i in range(n):
        n, x, y = f.readline().split()
        n = int(n)
        x, y = float(x), float(y)
        ns += [n]
        xs += [x]
        ys += [y]
    return ns, xs, ys

def draw_plot(xs, ys):
    for i in range(len(xs)):
        pyplot.plot(xs[i], ys[i], marker = "o", color = "red")
        pyplot.annotate(str(i+1), (xs[i],ys[i]))
    # Activar això si volem mostrar el plot amb els 33.708 punts:
    # pyplot.xlim(xmin = 9000, xmax = 30000)
    # pyplot.ylim(ymin = 86500, ymax = 107500)
    pyplot.show()

def tspHeuristic(ns, xs, ys):
    
    actual = 0
    n, x, y = ns.pop(actual), xs.pop(actual), ys.pop(actual)
    path = [actual]
    
    while len(ns) > 1:

        # Per anar veient el progrés del codi
        # (especialment en textos amb moltes dades)        
        if len(ns) % 100 == 0:
            print("Missing:", len(ns), "points")

        d = 10**6
        minim = 10**6

        # Busquem a l'esquerra
        pos = actual - 1
        while pos >= 0 and d >= xs[pos] - x:
            dist = math.sqrt((xs[pos] - x)**2 + (ys[pos] - y)**2)
            if dist <= d:
                d = dist
                minim = pos
            pos -= 1

        # Busquem a la dreta
        pos = actual
        m = len(xs)
        while pos < m and d > xs[pos] - x:
            dist = math.sqrt((xs[pos] - x)**2 + (ys[pos] - y)**2)
            if dist < d:
                d = dist
                minim = pos
            pos += 1

        n, x, y = ns.pop(minim), xs.pop(minim), ys.pop(minim)
        actual = minim
        path += [n-1]

    path += [ns[0]-1]
    path += [path[0]]
    return path

def lenPath(path, xs, ys):
    long = 0
    for i in range(len(path)-1):
        long += math.sqrt((xs[path[i+1]] - xs[path[i]])**2 + (ys[path[i+1]] - ys[path[i]])**2)
    return long

def main():
    print('Building graph from file...')
    ns, xs, ys = build_graph('tspLargeData.txt')
    # print('Drawing plot...')
    # draw_plot(xs, ys)
    print('Computing shortest path...')
    path = tspHeuristic(ns, [e for e in xs], [e for e in ys])
    # Imprimim el camí (no fer-ho si hi ha moltes dades!)
    # print([e+1 for e in path])
    # Imprimim la longitud del camí "mínim"
    print(lenPath(path, xs, ys))
    # RESPOSTA PER A "tspLargeData.txt" (33708 punts):
    # 1203406.5012708856

if (__name__ == '__main__'):
	main()