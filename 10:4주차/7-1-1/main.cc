#include <iostream>
#include "magic_square.h"
using namespace std;

int main(void){
    int n;
    
    while (1)
    {
        cin >> n;

        if(n<3||n%2==0){
            break;
        }

        int **matrix = new int*[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[n]();
        }

        magic_square(n, matrix);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    return 0;
}