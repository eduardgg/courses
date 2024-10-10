
# A partir de l'algorisme de QuickSort, calculem el nombre
# de comparacions necessàries. Per cada iteració, això equival
# al nombre d'elements del "subarray" menys 1 (el propi pivot).


def _medianOfThree(v, low, high):
    mid = (low + high - 1) // 2
    a = v[low]
    b = v[mid]
    c = v[high - 1]
    if a <= b <= c:
        return mid
    if c <= b <= a:
        return mid
    if a <= c <= b:
        return high - 1
    if b <= c <= a:
        return high - 1
    return low

def _selectPivot(v, low, high, metode):
    # metode indica quin mètode usem: 1, 2 o 3
    # MÈTODE 1: El pivot és el primer element
    # MÈTODE 2: El pivot és l'últim element
    # MÈTODE 3: El pivot és la "median of three"
    M = [low, high - 1, _medianOfThree(v,low,high)]
    return M[metode - 1]
    
def _sort(a, low, high, comp):
    # i compta el nombre d'elements menors al pivot
    i = 0
    n = high - low
    if n <= 1:
        return
    comp[0] += n-1
    p = _selectPivot(a, low, high, METODE)
    a[low], a[p] = a[p], a[low]
    pivot = a[low]
    for j in range(n-1):
        if a[low + j + 1] < pivot:
            i += 1
            a[low + i], a[low + j + 1] = a[low + j + 1], a[low + i]
    a[low], a[low + i] = a[low + i], a[low]
    _sort(a, low, low + i, comp)
    _sort(a, low + i + 1, high, comp)

def sort(a):
    n = len(a)
    comp = [0]
    _sort(a, 0, n, comp)
    return comp[0]


lectura = open("IntegerArray_QuickSort.txt","r")
llegir = lectura.readlines()
lectura.close()
array = [int(k) for k in llegir]

# array = [4,2,5,2,3,3,3,8,9,3,8,0,0,2,5,1,0,6,7,3,5,5,2]
# array = [6,5,0,2,5,9,2,4,5,8,2]
# array = [0,1,2,3,4,5,6,7]
# array = [5,4,3,2,1,0]

METODE = 1
comparacions = sort(array)
print(" Mètode " + str(METODE) + ": " + str(comparacions))

# RESULTATS:
# Mètode 1: 162085
# Mètode 2: 164123
# Mètode 3: 138382