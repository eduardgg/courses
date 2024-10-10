 #include <iostream>
 using namespace std;
 
 int main() {
	 int a,b,c,d;
	 cin >> a >> b >> c >> d;
	 if (a==c and b==d) cout << "=" << endl;
	 else if (a>=c and b<=d) cout << "1" << endl;
	 else if (a<=c and b>=d) cout << "2" << endl;
	 else cout << "?" << endl;
 }
