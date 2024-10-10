#include <iostream>
#include <cmath>
using namespace std;
void gira_paraules(){
	string mot;
	if ((cin >> mot) and (mot != "fi")) {
		gira_paraules();
	cout << mot << endl;
	
}
}
int main(){

	gira_paraules();
} 
