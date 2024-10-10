#include <iostream>
using namespace std;

int main() {
        int x,y,z;
        cin >> x >> y >> z;
        int s = (z+1)%60; //segons
        int m = (y+(z+1)/60)%60; //minuts
        int h = x+ (y+(z+1)/60)/60; //hores
       
        if (h == 24) cout << "00" << ":"; 
        if (h < 10) cout << 0 << h << ":";
        if (h >=10 and h < 24) cout << h << ":";
        
        if (m < 10) cout << 0 << m << ":";
        else cout << m << ":";
        
        if (s < 10) cout << 0 << s << endl;
        else cout << s << endl;
}
