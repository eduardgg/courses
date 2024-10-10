#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n<10) {
      cout << "El producte dels digits de " << n << " es " << n << "." << endl;
    }
    while (n>9) {
      int x = n;
      int p = 1;
      while (x>0) {
	p = p*(x%10);
	x = x/10;
      }
      cout << "El producte dels digits de " << n << " es " << p << "." << endl;
      n = p;
    }
    cout << "----------" << endl;
  }
} 
