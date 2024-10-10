
# Integer Multiplication
# School Algorithm:

def school_product(s1,s2):

    s1 = s1[::-1]
    s2 = s2[::-1]
    p = ""
    res = 0

    for i in range(len(s1)):
        producte = 0
        for j in range(i+1):
            producte += int(s1[j])*int(s2[i-j])
        producte += res
        p += str(producte % 10)
        res = producte // 10

    for i in range(len(s1)-1):
        producte = 0
        for j in range(len(s1)-1-i):
            producte += int(s1[i+1+j])*int(s2[len(s1)-1-j])
        producte += res
        p += str(producte % 10)
        res = producte // 10

    return p[::-1]

def xifres(i):
    if i//10 == 0:
        return 1
    return 1 + xifres(i//10)

# Integer Multiplication
# Karatsuba Algorithm:

def karatsuba(i1,i2):
    if xifres(i1) == 1:
        return i1 * i2
    n = xifres(i1) // 2
    i11 = i1 // (10**n)
    i12 = i1 % (10**n)
    i21 = i2 // (10**n)
    i22 = i2 % (10**n)
    a = karatsuba(i11,i21)
    b = karatsuba(i12,i22)
    c = karatsuba(i11+i12,i21+i22)
    d = c-a-b
    return a*(100**n) + d*(10**n) + b

i1 = 3141592653589793238462643383279502884197169399375105820974944592
i2 = 2718281828459045235360287471352662497757247093699959574966967627

print("School Algogithm: " + school_product(str(i1),str(i2)))
print("Karatsuba Algorithm: " + str(karatsuba(i1,i2)))
print("Python Product: " + str(i1*i2))