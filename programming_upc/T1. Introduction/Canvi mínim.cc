#include <iostream>
using namespace std;

int main () {
	int x,y;
	cin >> x >> y;
	int a = x/500; //Bitllets de 500 euros
	int b = (x-500*a)/200; //Bitllets de 200 euros
	int c = (x-500*a-200*b)/100; //Bitllets de 100 euros
	int d = (x-500*a-200*b-100*c)/50; //Bitllets de 50 euros
	int e = (x-500*a-200*b-100*c-50*d)/20; //Bitllets de 20 euros
	int f = (x-500*a-200*b-100*c-50*d-20*e)/10; //Bitllets de 10 euros
	int g = (x-500*a-200*b-100*c-50*d-20*e-10*f)/5; //Bitllets de 5 euros
	int h = (x-500*a-200*b-100*c-50*d-20*e-10*f-5*g)/2; //Monedes de 2 euros
	int i = (x-500*a-200*b-100*c-50*d-20*e-10*f-5*g-2*h); //Monedes de 1 euro
	int j = y/50; //Monedes de 50 centims
	int k = (y-50*j)/20; //Monedes de 20 centims
	int l = (y-50*j-20*k)/10; //Monedes de 10 centims
	int m = (y-50*j-20*k-10*l)/5; //Monedes de 5 centims
	int n = (y-50*j-20*k-10*l-5*m)/2; //Monedes de 2 centims
	int o = (y-50*j-20*k-10*l-5*m-2*n); //Monedes de 1 centim
	cout << "Bitllets de 500 euros: " << a << endl;
	cout << "Bitllets de 200 euros: " << b << endl;
	cout << "Bitllets de 100 euros: " << c << endl;
	cout << "Bitllets de 50 euros: " << d << endl;
	cout << "Bitllets de 20 euros: " << e << endl;
	cout << "Bitllets de 10 euros: " << f << endl;
	cout << "Bitllets de 5 euros: " << g << endl;
	cout << "Monedes de 2 euros: " << h << endl;
	cout << "Monedes de 1 euro: " << i << endl;
	cout << "Monedes de 50 centims: " << j << endl;
	cout << "Monedes de 20 centims: " << k << endl;
	cout << "Monedes de 10 centims: " << l << endl;
	cout << "Monedes de 5 centims: " << m << endl;
	cout << "Monedes de 2 centims: " << n << endl;
	cout << "Monedes de 1 centim: " << o << endl;
}
