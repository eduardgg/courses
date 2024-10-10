

def optAllignment(penGap, pens, gen1, gen2):

    m = len(gen1)
    n = len(gen2)
    A = [[0 for j in range(n+1)] for i in range(m+1)]
    
    for i in range(m+1):
        A[i][0] = i*penGap
    for j in range(n+1):
        A[0][j] = j*penGap

    for i in range(m):
        for j in range(n):
            A[i+1][j+1] = min(
                A[i][j] + pens[gen1[i]+gen2[j]],
                A[i+1][j] + penGap,
                A[i][j+1] + penGap
                )

    # Imprimim la taula de penalitzacions:
    # print(A)
    for a in A:
        for b in a:
            print(b, end = " "*(4-len(str(b))))
        print()
    
    # Trobem quin és l'allignment òptim:
    gen1nou = ""
    gen2nou = ""
    i, j = m, n
    while i > 0 and j > 0:
        if A[i][j] == A[i][j-1] + penGap:
            gen1nou += "-"
            gen2nou += gen2[j-1]
            j -= 1
        elif A[i][j] == A[i-1][j] + penGap:
            gen1nou += gen1[i-1]
            gen2nou += "-"
            i -= 1
        else:
            gen1nou += gen1[i-1]
            gen2nou += gen2[j-1]
            i -= 1
            j -= 1

    # FALTA TESTEJAR AQUESTA PART !!!!!
    # CAL ALGUN EXEMPLE EN EL QUÈ L'ÒPTIM ACABI O COMENCI EN FORATS
    for x in range(i):
        gen1nou += gen1[i-1-x]
        gen2nou += "-"
    for y in range(j):
        gen1nou += "-"
        gen2nou += gen2[j-1-y]

    print(gen1nou[::-1])
    print(gen2nou[::-1])

    # Penalització mínima:
    return A[-1][-1]




# Dades meves inventades:
gen1 = "AGGGCT"
gen2 = "AGGCA"
penGap = 3
pens = {
    "AA":0, "AC":3, "AG":4, "AT":3, 
    "CA":3, "CC":0, "CG":2, "CT":2,
    "GA":4, "GC":2, "GG":0, "GT":5,
    "TA":3, "TC":2, "TG":5, "TT":0  
    }

print(optAllignment(penGap, pens, gen1, gen2))