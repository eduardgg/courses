#include <iostream>
#include <vector>
using namespace std;


vector<double> fusio(const vector<double>& v1, const vector<double>& v2) {  
    int n1 = v1.size();
    int n2 = v2.size();
    int n3 = n1 + n2;
    vector<double> res (n3);
    int i = 0; 
    int j = 0; 
    int k = 0;
    while (i < n1 and j < n2) {
        if (v1[i] < v2[j]) {
            res[k] = v1[i];
            ++i;
        }
        else {
            res[k] = v2[j];
            ++j;
        }
        ++k;
    }
    if (i == n1) {
        for (int r = j; r < n2; ++r) {
            res[k] = v2[r];
            ++k;
        }
    }
    else {
        for (int r = i; r < n1; ++r) {
            res[k] = v1[r];
            ++k;
        }
    }
    return res;
}

int main () {

} 
