
from random import randint

class TreeNode(object):
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def printM(A):
    for a in A:
        for e in a:
            # Augmentar el 4 si es volen tamanys més grans
            print(e, end = " "*(4-len(str(e))))
        print()
    print()

# Funció recursiva basada en Dynamic Programming per trobar el BST
# (Binary Search Tree) òptim, donades les freqüències dels elements.
def bestBST1(freqs):
    n = len(freqs)
    A = [[0 if i >= j else -1 for j in range(n)] for i in range(n)]
    for i in range(n):
        A[i][i] = freqs[i]
    
    def dp(i, j):
        if min(i,j) < 0 or max(i,j) > n-1:
            return 0
        if A[i][j] != -1:
            return A[i][j]
        sumaFreqs = sum([freqs[a] for a in range(i,j+1)])
        separacio = min([dp(i,k-1) + dp(k+1,j) for k in range(i,j+1)])
        A[i][j] = sumaFreqs + separacio
        return A[i][j]

    resultat = dp(0, n-1)
    # Imprimim la matriu de resultats (necessaris):
    # printM(A)

    return resultat
    
# Aquí calculem tots els valors, sense recursivitat.
# A més, (només) en aquesta funció també calculem els pares de cada
# interval, és a dir, donat l'interval (i,j), calculem els elements
# de la matriu pares[i][j] com la posició de l'element central que 
# minimitzaria el cost del subarbre en qüestió (BST òpim).
def bestBST2(freqs):
    n = len(freqs)
    A = [[0 if i >= j else -1 for j in range(n)] for i in range(n)]
    pares = [[0 for j in range(n)] for i in range(n)]
    for i in range(n):
        pares[i][i] = i

    for i in range(n):
        A[i][i] = freqs[i]
    for i in range(1,n):
        for j in range(n-i):
            minim = A[j][j+i-1]
            pos = j+i
            if A[j+1][j+i] < minim:
                minim = A[j+1][j+i]
                pos = j
            for k in range(j+1,j+i):
                if A[j][k-1] + A[k+1][j+i] < minim:
                    minim = A[j][k-1] + A[k+1][j+i]
                    pos = k
            A[j][j+i] = minim + sum([freqs[a] for a in range(j,j+i+1)])
            pares[j][j+i] = pos

            # També es pot abreviar molt amb la següent fórmula:
            # (però llavors no es pot trobar la posició del mínim)
            # A[j][j+i] += min([A[j][k-1] + A[k+1][j+i] for k in range(j+1,j+i)] + [A[j][j+i-1]] + [A[j+1][j+i]])

    # printM(A)
    return (A[0][n-1], pares)

def arbre(node, i, j):
    global pares
    node.val = pares[i][j]
    if node.val > i:
        node.left = TreeNode()
        arbre(node.left, i, node.val-1)
    if node.val < j:
        node.right = TreeNode()
        arbre(node.right, node.val+1, j)
    return

# -------------------- PROVES --------------------

# Comparació dels dos codis amb 3 mostres concretes
"""
f1 = [6, 2, 5, 8, 7, 3]
f2 = [10, 10, 5, 2, 1, 1]
f3 = [4, 3, 10, 5, 5, 8]
print(bestBST1(f1))
print(bestBST2(f1))
print(bestBST1(f2))
print(bestBST2(f2))
print(bestBST1(f3))
print(bestBST2(f3))
"""

# Comparació dels dos codis amb una mostra aleatòria
"""
randf = [randint(1,10) for i in range(10)]
print(randf)
bst1 = bestBST1(randf)
print(bst1)
bst2, pares = bestBST2(randf)
print(bst2)
"""

# Fem proves amb una mostra més gran (tamany 10)
"""
f = [9, 3, 4, 5, 9, 2, 9, 3, 4, 3]
print(f)
bst, pares = bestBST2(f)
printM(pares)
root = TreeNode()
arbre(root, 0, len(f)-1)

# IMPRIMIM NOMÉS PER VISUALITZAR L'EXEMPLE:
print(10*" ", f[root.val])
print(4*" ", f[root.left.val], 12*" ", f[root.right.val])
print(6*" ", f[root.left.right.val], 7*" ", f[root.right.left.val], 3*" ", f[root.right.right.val])
print(4*" ", f[root.left.right.left.val], 2*" ", f[root.left.right.right.val], 8*" ", f[root.right.right.left.val], 2*" ", f[root.right.right.right.val])
"""

# PROBLEM SET 4:
print()
f = [0.05, 0.4, 0.08, 0.04, 0.1, 0.1, 0.23]
resultat1 = bestBST1(f)
resultat2, pares = bestBST2(f)
if resultat1 == resultat2:
    print(resultat1)
    for i in pares:
        print(i)

# FINAL EXAM - Problem 10:
print()
f = [0.2, 0.05, 0.17, 0.1, 0.2, 0.03, 0.25]
resultat1 = bestBST1(f)
resultat2, pares = bestBST2(f)
if resultat1 == resultat2:
    print(resultat1)
    for i in pares:
        print(i)