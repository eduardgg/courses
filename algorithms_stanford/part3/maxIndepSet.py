
def load_path(filename):
    
    with open(filename, 'r') as f:
        n = int(f.readline())
        weights = []
        for i in range(n):
            weights += [int(f.readline())]
    return weights


def maxIndepSet(v):

    # Resolem la programació dinàmica
    A = []
    A.append(v[0])
    A.append(v[1])
    for i in range(len(v)-2):
        A.append(max(A[i+1], v[i+2]+A[i]))

    # Trobem els elements del màxim conjunt independent:
    posicions = ""
    indSet = []
    i = len(v)-1
    while i > 1:
        if A[i-2] + v[i] > A[i-1]:
            indSet.append(v[i])
            posicions += "10"
            i -= 2
        else:
            posicions += "0"
            i -= 1
            
    # Afegim els casos base (i=0 o i=1):
    # indSet.append(max(v[:i+1]))
    if i == 0:
        indSet.append(v[0])
        posicions += "1"
    elif v[0] > v[1]:
        indSet.append(v[0])
        posicions += "01"
    else:
        indSet.append(v[1])
        posicions += "10"
    
    # Valors del màxim conjunt independent:
    # Elements i posicions del màxim conjunt independent:
    return indSet[::-1], posicions[::-1]


def main():
    
    weights = load_path("mwis.txt")
    indSet, posicions = maxIndepSet(weights)
    print(posicions)

    str = ""
    for i in [1,2,3,4,17,117,517,997]:
        str += posicions[i-1]
    print(str)
    # Solució: 10100110


    # ALTRES PROVES:
    u = [1, 1, 2, 2, 3, 4, 4, 5, 6]
    v = [1, 4, 5, 4]
    w = [8, 6, 5, 2, 9, 7, 4]
    print(maxIndepSet(u))
    print(maxIndepSet(v))
    print(maxIndepSet(w))


if (__name__ == '__main__'):
	main()