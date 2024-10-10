#include <iostream>
#include <vector>
using namespace std;

int min (int& a, int& b) {
    if (a < b) return a;
    else return b;
}

vector<double> interseccio(const vector<double>& v1, const vector<double>& v2) {  
    int n1 = v1.size();
    int n2 = v2.size();
    vector<double> aux (min(n1, n2));
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 and j < n2) {
        if (k == 0) {
            if (v1[i] == v2[j]) {
                aux[k] = v1[i];
                ++i;
                ++j;
                ++k;
            }
            else {
                if (v1[i] < v2[j]) ++i;
                else ++j;
            }
        }
        
        else {
            if (v1[i] == v2[j] and v1[i] != aux[k-1]) {
                aux[k] = v1[i];
                ++i;
                ++j;
                ++k;
            }
            else {
                if (v1[i] < v2[j]) ++i;
                else ++j;
            }
        }
    }
    
    vector<double> res (k);
    for (int r = 0; r < k; ++r) res[r] = aux[r];
    return res;
}

int main () {
    
} 
