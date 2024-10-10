 #include <iostream>
 using namespace std;
 
 int main() {
	 int a,b;
	 cin >> a >> b;
	 int c=a;
	 int d=b;
	 while (a!=b) {
		 if (a>b) a=a-b;
		 if (a<b) b=b-a;
	 }
	 cout << "El mcd de " << c << " i " << d << " es " << a << "." << endl;
 }
