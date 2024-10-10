
def knapsack(v, w, W):
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



"""
Explicació del Mètode:
Es tracta d'un arxiu amb moltíssimes dades, de manera que cap dels
dos mètodes de programació dinàmica (per recursivitat, i memoritzant
les solucions de tots els subproblemes) no funcionen.
El que fem aquí és retallar les dades. A priori, i a part del codi,
hem ordenat els vectors de valors i de pesos segons els seus mateixos
valors i també segons la relació v/w (o w/v).
Que w/v sigui alt és dolent, però no permet desconsiderar-ho, ja que
podria tenir un pes molt baix i encaixar en algun forat.
Que w sigui alt també és dolent, però podria tenir la millor relació
w/v del problema i, per tant, l'hauríem d'incloure.
El que està clar, però, és que quan tant el pes w com la relació w/v
siguin alts, és molt probable que quedin descartats, i més encara si
el tamany W és força just i una petita part dels elements ja superen
això. Cal analitzar-ho més cuidadosament, i està clar que depèn de
cada problema, però aquest truc permet reduir moltíssim la quantitat
d'elements (en aquest cas, de 2000 dades a només 117, però els
llindars de w i de w/v no es poden reduir gaire més...)
QUEDA PENDENT: Analitar com escollir els "filtres" òptims.
"""

with open("knapsack_big.txt", 'r') as f:
    W, n = f.readline().split()
    W, n = int(W), int(n)
    
    # A = []
    # B = []
    # C = []

    values = []
    weights = []
    for i in range(n):
        v, w = f.readline().split()
        v, w = int(v), int(w)
        if w/v > 1 and w > 50000:
            continue
        values += [v]
        weights += [w]

        # A += [(w/v, w, v)]
        # B += [(w, v)]
        # C += [(v, w)]

# A.sort()
# B.sort()
# C.sort()

print("Nombre d'elements: ", n)
print("Després del filtre: ", len(values))
print("Knapsack: ", knapsack(values, weights, W))
# Solució: 4243395 (CORRECTE!)