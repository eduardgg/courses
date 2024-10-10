#include <iostream> 
#include <cmath> 
using namespace std; 
void gira_paraules(int n, int& i){
	string mot;
	if ((cin >> mot) and (i<n)) {
		i++;
		gira_paraules(n,i);
	cout << mot << endl;
	
}
}
int main(){
	int n;
	cin >> n;
	int i=0;
	gira_paraules(n,i);
}
