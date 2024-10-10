#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    
 double x, n;
 cin >> x;
 cin >> n;
 double s=n;
 double i=x;
 while (cin >> n){
        n=n*i;
        i=i*x;
        s=s+n;
    }
    cout << s << endl;
    
    
    
}
 
