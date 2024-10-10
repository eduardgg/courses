#include <iostream>
using namespace std;

int main() {
int d, m, a;
while (cin >> d >> m >> a) {
if (m>=1 and m<=12) {
    if (m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12){
        if (d>=1 and d<=31) cout << "Data Correcta" << endl;
        else cout << "Data Incorrecta" << endl;
    }
    else if (m==2) {
		if (d==29) {
			if (a%4==0 and a%100 != 0) cout << "Data Correcta" << endl;
			else if (a%400==0) cout << "Data Correcta" << endl;
			else cout << "Data Incorrecta" << endl;
		}
        else if (d>=1 and d<=28) cout << "Data Correcta" << endl;
        else cout << "Data Incorrecta" << endl;
    }
    else if (m==4 or m==6 or m==9 or m==11) {
        if (d>=1 and d<=30) cout << "Data Correcta" << endl;
        else cout << "Data Incorrecta" << endl;
    }  
}
else cout << "Data Incorrecta" << endl;
}
}
