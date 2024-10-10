// Heapify en temps lineal.


#include <iostream>
#include <vector>
using namespace std;


const int MAX = 1000;


typedef vector<int> VE;


int n = 0;
VE V(MAX);


void enfonsa(int i) {
  while (2*i <= n) {
    int f = 2*i;
    int fd = 2*i + 1;
    if (fd <= n and V[fd] > V[f]) f = fd;
    if (V[i] >= V[f]) return;
    swap(V[i], V[f]);
    i = f;
  }
}


int main() {
  int x;
  while (cin >> x) V[++n] = x;
  for (int i = n; i >= 1; --i) enfonsa(i);
}
