import collections
import itertools

from union_find_internet import UnionFind
from tqdm import tqdm

def flip(bit):

    return '0' if bit=='1' else '1'

def getNeiborhood(bits):

    for i in range(len(bits)):
        yield bits[:i] + (flip(bits[i]),) + bits[i+1:]
    
    for i, j in itertools.permutations(range(len(bits)), 2):
        if i < j:
            yield bits[0:i] + (flip(bits[i]),) + bits[i+1:j] + (flip(bits[j]),) + bits[j+1:]


def Clustering(nodes):

    UnionNodes = UnionFind(nodes.keys())

    for node in tqdm(nodes):
        for neighbour in getNeiborhood(node):
            if neighbour not in nodes:
                continue
            if not UnionNodes.connected(node, neighbour):
                UnionNodes.union(node, neighbour)

    return UnionNodes


if __name__ == "__main__":
    
    txtFile = 'clustering_big.txt'
    data = collections.defaultdict()
    with open(txtFile, 'r') as f:
        for line in f.readlines()[1:]:
            nums = line.split()
            # data.append(tuple(nums))
            data[tuple(nums)] = tuple(nums)

    # print(data[:5])
    # cluster1 = Cluster(data)
    # print(cluster1.clustering())

    unionNodes = Clustering(data)
    print(unionNodes.n_comps)