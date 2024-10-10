
def greedyDifference(filename):
    f = open(filename, "r")
    n = int(f.readline())
    v = []
    for i in range(n):
        w, l = f.readline().split()
        w, l = int(w), int(l)
        v += [(w-l,w,l)]
    v.sort()
    v = v[::-1]
    time = 0
    compTime = 0
    for j in v:
        time += j[2]
        compTime += time * j[1]
    print("Greedy sorted by difference:")
    print("Completion Time:", compTime)
    print()

def greedyQuotient(filename):
    f = open(filename, "r")
    n = int(f.readline())
    v = []
    for i in range(n):
        w, l = f.readline().split()
        w, l = int(w), int(l)
        v += [(w/l,w,l)]
    v.sort()
    v = v[::-1]
    time = 0
    compTime = 0
    for j in v:
        time += j[2]
        compTime += time * j[1]
    print("Greedy sorted by quotient:")
    print("Completion Time:", compTime)
    print()


def main():
    
    greedyDifference('jobs.txt')
    # Resposta: Completion Time = 69119377652

    greedyQuotient('jobs.txt')
    # Resposta: Completion Time = 67311454237

if (__name__ == '__main__'):
	main()