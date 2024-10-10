// Compta totes les sequencies de 0s i 1s amb n bits de forma eficient.


#include <iostream>
using namespace std;


int n;


int f(int i) {
  if (i == n) return 1;
  return 2*f(i + 1);
}


int main() {
  cin >> n;
  cout << f(0) << endl;
}
