#include <iostream>
using namespace std;

int main () {
    int b, h, d;
    while (cin >> b >> h >> d) {
        int i, j;
        for (i = 0; i < d; ++i) cout << ' ';
        for (i = 0; i <= b; ++i) cout << '_';
        cout << endl;
        for (i = 1; i < d; ++i) {
            for (j = 0; j < d - i; ++j) cout << ' ';
            cout << '/';
            for (j = 0; j < b; ++j) cout << ' ';
            cout << '/';
            for (j = 1; j < i; ++j) cout << ' ';
            cout << '|' << endl;
        }
        for (j = 0; j < d - i; ++j) cout << ' ';
        cout << '/';
        for (j = 0; j < b; ++j) cout << '_';
        cout << '/';
        for (j = 1; j < i; ++j) cout << ' ';
        cout << '|' << endl;
        
        for (i = 0; i < h - d; ++i) {
            cout << '|';
            for (j = 0; j < b; ++j) cout << ' ';
            cout << '|';
            for (j = 1; j < d; ++j) cout << ' ';
            cout << '|' << endl;
        }
        
        for (i = 1; i < d; ++i) {
            cout << '|';
            for (j = 0; j < b; ++j) cout << ' ';
            cout << '|';
            for (j = 0; j < d - i; ++j) cout << ' ';
            cout << '/' << endl;
        }
        
        cout << '|';
        for (i = 0; i < b; ++i) cout << '_';
        cout << "|/" << endl << endl;
    }
} 
