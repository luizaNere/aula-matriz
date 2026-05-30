#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define x 10

using namespace std;

int main() {
    srand(time(0));
    int matriz[x][x];
    int maior = -99;
    
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            matriz[i][j] = rand() % 200 - 99;
            cout << setw(4) << matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            if(i == 0) {
                cout << setw(4) << matriz[i][j];
            } else if(j == 0) {
                cout << setw(4) << matriz[i][j];
            } else if(i == j) {
                cout << setw(4) << matriz[i][j];
            } else if(i == (x-1)) {
                cout << setw(4) << matriz[i][j];
            } else if(j == (x-1)) {
                cout << setw(4) << matriz[i][j];
            } else if((i+j) == (x-1)) {
                cout << setw(4) << matriz[i][j];
            } else {
                cout << "    ";
            }
        }
        cout << endl;
    }

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            if(matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }    
    cout << "\nMaior valor = " << maior;
}