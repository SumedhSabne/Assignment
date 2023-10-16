#include <iostream>
using namespace std;

int main() {
    int numRows, numCols, numElements;
    cin >> numRows >> numCols >> numElements;

    int matrix[numRows][numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = 0;
        }
    }

    int row, col, value;
    for (int x = 0; x < numElements; x++) {
        cin >> row >> col >> value;
        matrix[row][col] = value;
    }

    int centerRow = (numRows / 2) - 1;
    int up = 0, down = 0, right = 0, left = 0;
    int increment1 = 1, increment2 = 2;
    int currentRow = centerRow, currentCol = centerRow;
    if (matrix[currentRow][currentCol]) {
        cout << matrix[currentRow][currentCol] << "1 ";
        down = 1;
    }

    while (currentRow != 0 && currentCol != numCols - 1) {
        while (increment1 != numElements - 2 && increment2 != numElements - 3) {
            if (down == 1) {
                currentRow = currentRow + increment1;
                if (matrix[currentRow][currentCol]) {
                    cout << matrix[currentRow][currentCol] << "1 ";
                }
                right = 1;
                down = 0;
                up = 0;
                left = 0;
            }
            if (right == 1) {
                currentCol = currentCol + increment1;
                if (matrix[currentRow][currentCol]) {
                    cout << matrix[currentRow][currentCol] << "2 ";
                }
                right = 0;
                down = 0;
                up = 1;
                left = 0;
            }
            if (up == 1) {
                currentRow = currentRow - increment2 + 1;
                if (matrix[currentRow][currentCol]) {
                    cout << matrix[currentRow][currentCol] << "3 ";
                }
                currentRow = currentRow - 1;
                right = 0;
                down = 0;
                up = 0;
                left = 1;
            }
            if (left == 1) {
                currentCol = currentCol - increment2;
                if (matrix[currentRow][currentCol]) {
                    cout << matrix[currentRow][currentCol] << "4 ";
                }
                right = 0;
                down = 1;
                up = 0;
                left = 0;
            }
            increment1 = increment1 + 2;
            increment2 = increment2 + 2;
        }
    }

    return 0;
}

