
# Ho fem a partir de la implementació de Merge Sort,
# simplement afegint la variable inv (com a vector,
# per tal que sigui mutable durant la recurrència),
# i modificant-la quan es fa la subfunció "merge".

def _merge(a, lo, mid, hi):
    global inv
    n = hi - lo
    i = lo
    j = mid
    aux = [0]*n
    for k in range(n):
        if i == mid:
            aux[k] = a[j]
            j += 1
        elif j == hi:
            aux[k] = a[i]
            i += 1
            inv += j-mid
        elif a[j] < a[i]:
            aux[k] = a[j]
            j += 1
        else:
            aux[k] = a[i]
            i += 1
            inv += j-mid
    a[lo:hi] = aux[0:n]

def _sort(a, lo, hi):
    n = hi - lo
    if n <= 1:
        return
    mid = (lo + hi) // 2
    _sort(a, lo, mid)
    _sort(a, mid, hi)
    _merge(a, lo, mid, hi)

def sort(a):
    n = len(a)
    _sort(a, 0, n)


lectura = open("IntegerArray_MergeSort.txt","r")
llegir = lectura.readlines()
lectura.close()
array = [int(k) for k in llegir]

inv = 0
sort(array)
print(inv)

# print(array)
# Resposta a l'arxiu "IntegerArray_MergeSort.txt":
# 2407905288