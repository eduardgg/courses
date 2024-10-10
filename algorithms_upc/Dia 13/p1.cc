// Calcula si una posicio del nim es guanyadora o no, sense usar nimbers.


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


typedef vector<int> VE;
typedef map<VE, int> MVE;
typedef MVE::iterator MI;


MVE M;


bool guanya(VE& V) {
  sort(V.begin(), V.end());
  MI p = M.find(V);
  if (p != M.end()) return p->second;

  int n = V.size();
  if (n == 0) return (M[V] = false);
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < V[i]; ++j) {
      VE A = V;
      A[i] = j;
      if (not guanya(A)) return (M[V] = true);
    }
    VE B;
    for (int k = 0; k < n; ++k)
      if (k != i) B.push_back(V[k]);
    if (not guanya(B)) return (M[V] = true);
  }
  return (M[V] = false);
}


int main() {
  int n;
  cin >> n;
  VE V(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  cout << guanya(V) << endl;
}
