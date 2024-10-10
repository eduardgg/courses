// Exemple d'us de cues de prioritats.


#include <iostream>
#include <queue>
using namespace std;


int main() {
  int x;
  priority_queue<int, vector<int>, greater<int> > Q;
  while (cin >> x) Q.push(x);

  while (not Q.empty()) {
    int y = Q.top(); Q.pop();
    cout << y << endl;
  }
}
