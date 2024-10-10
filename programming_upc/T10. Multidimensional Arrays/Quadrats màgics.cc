#include <iostream>
#include <vector>

using namespace std;
typedef vector <vector <int> > Matrix;

int main(){
    int n, sumadia, sumafila, sumacol, sumaotradia;;
    bool pene;
    while (cin >> n){
        vector <bool> chocho (n*n, false);
        Matrix a (n,vector <int>(n));
        pene = true;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){      /*Introducimos los terminos de la matriz*/
                cin >> a[i][j];
                if(a[i][j] <= n*n and a[i][j] > 0 and not chocho[a[i][j] - 1] ) chocho[a[i][j] - 1] = true;
                else pene = false;
            }
        }
        sumadia = 0;
        sumaotradia = 0;
        for (int i = 0;i < n; i++) sumaotradia += a[i][n-1-i];
        for (int i = 0;i < n;i++) sumadia += a[i][i];
        if (sumaotradia != sumadia) pene = false;
        for (int i = 0;i < n;i++){
            sumafila = sumacol = 0;
            for (int j = 0;j < n;j++){
                sumafila += a[i][j];
                sumacol += a[j][i];
            }
            if (sumadia != sumacol) pene = false;
            if (sumadia != sumafila) pene = false;
        }
        if(pene) cout << "si" << endl;
        else cout << "no" << endl;  
    }  
}  
