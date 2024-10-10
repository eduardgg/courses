
def knapsack1(v, w, W):
    # Sense funcions recursives
    # Calculem TOTS els valors (O(n*W)) amb un bucle
    # Retornem l'últim valor trobat de la taula
    n = len(v)
    A = [[0 for x in range(W+1)] for i in range(n+1)]
    for i in range(n):
        for x in range(W+1):
            if x < w[i]:
                A[i+1][x] = A[i][x]
            else:
                A[i+1][x] = max(A[i][x], A[i][x-w[i]] + v[i])
    
    # La matriu A és plena (coneixem tots els valors)
    # print(A)
    # printMat(A)

    return A[-1][-1]

def knapsack2(v, w, W):
    # Amb funció recursiva
    # Calculem només els valors necessaris
    n = len(v)
    A = [[-1 for x in range(W+1)] for i in range(n+1)]
    A[0] = [0 for x in range(W+1)]

    def dp(i, x, w):
        if A[i][x] != -1:
            return A[i][x]
        if A[i-1][x] == -1:
            A[i-1][x] = dp(i-1, x, w)
        if x < w[i-1]:
            return A[i-1][x]
        if A[i-1][x-w[i-1]] == -1:
            A[i-1][x-w[i-1]] = dp(i-1, x-w[i-1], w)
        
        """        
        # Veiem com ha quedat la matriu A
        # Els "-1" són els valors que no ha calgut calcular
        print(A)
        if i == n and x == W:
            printMat(A)
        """

        return max(A[i-1][x], A[i-1][x-w[i-1]] + v[i-1])

    return dp(n, W, w)

def printMat(A):
    for a in A:
        for e in a:
            if e == -1:
                e = "-"
            print(e, end = " "*(4-len(str(e))))
        print()
    print()




filename = "knapsack1.txt"

with open(filename, 'r') as f:
    W, n = f.readline().split()
    W, n = int(W), int(n)
    v = []
    w = []
    for i in range(n):
        vv, ww = f.readline().split()
        v += [int(vv)]
        w += [int(ww)]

# print(knapsack1(v, w, W))
print(knapsack2(v, w, W))

# Solució per a "knapsack1.txt": 2493893
# Solució per a "knapsack_big.txt": - (massa gran)





"""
# EXEMPLE:
v = [3,2,4,4]
w = [4,3,2,3]
W = 6

print(knapsack1(v, w, W))
print(knapsack2(v, w, W))
"""