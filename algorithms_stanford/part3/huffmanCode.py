import heapq

class TreeNode(object):
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    # Això ens cal per desempatar arbitràriament en
    # cas que el heap requereixi comparar dos TreeNode.
    def __lt__(self, other):
        return True
    """
    def __eq__(self, other):
    def __ne__(self, other):
    def __lt__(self, other):
    def __le__(self, other):
    def __gt__(self, other):
    def __ge__(self, other):
    """

def huffman(freqs):
    heap = []
    code = dict()
    for key in freqs.keys():
        heapq.heappush(heap, (freqs[key], TreeNode(key)))
    while len(heap) > 1:
        freq1, t1 = heapq.heappop(heap)
        freq2, t2 = heapq.heappop(heap)
        heapq.heappush(heap, (freq1 + freq2, TreeNode(left=t1, right=t2)))
    origin = heapq.heappop(heap)[1]
    stack = [(origin, "")]
    while len(stack) > 0:
        node, str = stack.pop()
        if not node.left and not node.right:
            code[node.val] = str
            continue
        stack.append((node.right, str + "1"))
        stack.append((node.left, str + "0"))
    return code

def inverse(dic):
    inv = dict()
    for key in dic.keys():
        inv[dic[key]] = key
    return inv

def encode(str, coding):
    s = ""
    for i in range(len(str)):
        s += coding[str[i]]
    return s

def decode(str, decoding):
    s = ""
    sub = ""
    for i in range(len(str)):
        sub += str[i]
        if sub not in decoding.keys():
            continue
        s += decoding[sub]
        sub = ""
    return s

def averageLength(freqs, code):
    maxLen = 0
    minLen = 10**6
    totalFreq = 0
    sum = 0
    for key in freqs.keys():
        if len(code[key]) > maxLen:
            maxLen = len(code[key])
        if len(code[key]) < minLen:
            minLen = len(code[key])
        sum += freqs[key] * len(code[key])
        totalFreq += freqs[key]
    return sum/totalFreq, maxLen, minLen

def huffmanFromFile(filename):
    # En aquest cas,  seria més eficient definir freqs com un vector,
    # ja que el nom del caràcter no és rellevant. Però aprofitarem el
    # codi fet amb diccionaris, per no canviar tantes coses.
    with open(filename, 'r') as f:
        n = int(f.readline())
        freqs = {}
        for i in range(n):
            freqs[i] = int(f.readline())
    code = huffman(freqs)
    average, max, min = averageLength(freqs, code)
    # print(code)
    print("Average Length: ", average)
    print("Maximum Length: ", max)
    print("Maximum Length: ", min)
    return



# Programming Assignment:
huffmanFromFile("huffman.txt")

# Final Exam Part 3 (Problem 7)
print()
freqs = {'A': 0.28, 'B':0.27, 'C':0.2, 'D':0.15, 'E':0.1}
coding = huffman(freqs)
print(coding)
average, max, min = averageLength(freqs, coding)
print("Average Length: ", average)
print("Maximum Length: ", max)
print("Maximum Length: ", min)


# PROBLEM SET 3
print()
freqs = {'A': 0.32, 'B':0.25, 'C':0.2, 'D':0.18, 'E':0.05}
coding = huffman(freqs)
print(coding)
average, max, min = averageLength(freqs, coding)
print("Average Length: ", average)
print("Maximum Length: ", max)
print("Maximum Length: ", min)

# PROVA 1:
print()
freqs = {'A': 0.6, 'B':0.25, 'C':0.1, 'D':0.05}
coding = huffman(freqs)
decoding = inverse(coding)
print("Frequencies: ", freqs)
print("Huffman Code: ", coding)
average, max, min = averageLength(freqs, coding)
print("Average Length: ", average)
print("Maximum Length: ", max)
print("Maximum Length: ", min)
print("Encode ABCDBAC: " + encode("ABCDBAC", coding))
print("Decode 101001000011001: " + decode("101001000011001", decoding))

# PROVA 2:
print()
freqs = {'A':3, 'B':2, 'C':6, 'D':8, 'E':2, 'F':6}
coding = huffman(freqs)
print("Frequencies: ", freqs)
print("Huffman Code: ", coding)
print(coding)
average, max, min = averageLength(freqs, coding)
print("Average Length: ", average)
print("Maximum Length: ", max)
print("Maximum Length: ", min)