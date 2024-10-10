
def _merge(a, lo, mid, hi):
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
        elif a[j] < a[i]:
            aux[k] = a[j]
            j += 1
        else:
            aux[k] = a[i]
            i += 1
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
# array = [4,2,5,2,3,3,3,8,9,3,8,0,0,2,5,1,0,6,7,3,5,5,2]
# array = [6,5,0,2,5,9,2,4,5,8,2]
# array = [0,1,2,3,4,5]
# array = [5,4,3,2,1,0]

sort(array)
print(array)