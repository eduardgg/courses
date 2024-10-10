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
    int seq;
    cin >> seq;
    int n;
    for (int i = 0; i < seq; ++i)  {
        cin >> n;
        if (n == 1 or n == 0) cout << n << " is not prime" << endl;
        else if (is_prime(n)) cout << n << " is prime" << endl;
        else cout << n << " is not prime" << endl;
    }
} 
