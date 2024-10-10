import random

def randomSort(v):
    n = len(v)
    for i in range(len(v)):
        r = random.randint(i,n-1)
        v[i], v[r] = v[r], v[i]

def _sort(a, lo, hi):
    # i compta el nombre d'elements menors al pivot
    i = 0
    n = hi - lo
    if n <= 1:
        return
    pivot = a[lo]
    for j in range(n-1):
        if a[lo + j + 1] < pivot:
            i += 1
            a[lo + i], a[lo + j + 1] = a[lo + j + 1], a[lo + i]
    a[lo], a[lo + i] = a[lo + i], a[lo]
    _sort(a, lo, lo + i)
    _sort(a, lo + i + 1, hi)

def sort(a):
    randomSort(a)
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