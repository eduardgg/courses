#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void print_line(char c, string s, bool b){
	cout << s << "('" << c << "') = ";
if (b) cout << "true"<<endl;
else cout << "false" << endl;
}

int main (){
	char c;
	string s;
	cin >> c;
	bool majuscula = c >= 'A' and c <= 'Z';
	bool minuscula = c >= 'a' and c <= 'z';
	bool lletra = (majuscula or minuscula);
	bool vocal = ((c == 'a') or (c== 'e') or (c=='i') or (c=='o') or( c== 'u') or (c== 'A') or (c=='E') or (c== 'I') or(c== 'O') or (c== 'U'));
	bool consonant = (lletra and not vocal);
	bool digit = ((c >= '0') and (c<= '9'));
	s = "letter";
	print_line(c,s,lletra);
		s = "vowel";
	print_line(c,s,vocal);	
		s = "consonant";
	print_line(c,s,consonant);
	s = "uppercase";
	print_line(c,s,majuscula);

	s = "lowercase";
	print_line(c,s,minuscula);

	s = "digit";
	print_line(c,s,digit);
	
}
