#include <iostream>
using namespace std;

bool is_prime(int n) {
    int i = 2;
    bool not_prime = false;
    while (i*i <= n and not not_prime) {
        if (n%i != 0) not_prime = false;
        else not_prime = true;
        ++i;
    }
    if (not_prime) return false;
    else return true;
}

int main () {
    int n;
    while (cin >> n and is_prime(n)) {
        if (n == 1 or n == 0) break;
        ++n;
        while (not is_prime(n)) {
           ++n; 
        }
        if (is_prime(n)) cout << n << endl;
    }
} 
