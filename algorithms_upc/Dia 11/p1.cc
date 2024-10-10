// Operacions basiques d'un heap: push i pop.


#include <iostream>
#include <vector>
using namespace std;


const int MAX = 1000;


typedef vector<int> VE;


int n = 0;
VE V(MAX);


void push(int x) {
  V[++n] = x;
  int i = n;
  while (i > 1 and V[i/2] < V[i]) {
    swap(V[i/2], V[i]);
    i /= 2;
  }
}


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


void pop() {
  V[1] = V[n--];
  enfonsa(1);
}


int main() {
  char c;
  while (cin >> c) {
    if (c == 'i') {
      int x;
      cin >> x;
      push(x);
    }
    else pop(); // c == 'e'

    for (int i = 1; i <= n; ++i) cout << ' ' << V[i];
    cout << endl;
  }
}
