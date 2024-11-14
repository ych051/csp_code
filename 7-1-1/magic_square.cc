#include "magic_square.h"

void magic_square(int n, int **matrix) {
    int row = 0, col = n / 2;
    int num = 1;

    while (num <= n * n) {
        matrix[row][col] = num;
        num++;
        
        int next_row = (row - 1 + n) % n;
        int next_col = (col + 1) % n;

        if (matrix[next_row][next_col] != 0) {
            row = (row + 1) % n;
        } else {
            row = next_row;
            col = next_col;
        }
    }
}