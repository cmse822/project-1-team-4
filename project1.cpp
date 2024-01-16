// Project 1 - Matrix Multiplication

#include <iostream>

using namespace std;

float** createMatrix(int rows, int cols) {
    // "Double" Pointer: Create pointer to memory that stores rows of pointers
    float** matrix = new float*[rows];

    for (int i = 0; i < rows; i++) {  // Iterate over rows
        matrix[i] = new float[cols];  // Allocate memory for column at each row pointer
    }
    return matrix;
}

void deleteMatrix(float** matrix, int rows) {
    
    for (int i = 0; i < rows; i++) {  // Iterate over rows
        delete[] matrix[i];  // Deallocate memory for column at each row pointer
    }
    delete[] matrix;  // Deallocate memory for original row points
}

float** fillMatrixValues(float** matrix, int rows, int cols) {
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            matrix[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }   
    }
    return matrix;
}

void printMatrixValues(float** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;    
    }
}

int main() {

    /*
    Program to perform Matrix-Matrix Multiplication
    A = BC
    */

    int n = 10; // # Rows of B
    int m = 10; // # Columns of B & # Rows of C
    int p = 10; // # Coulmns of C

    float** A = createMatrix(n, p);
    float** B = createMatrix(n, m);
    float** C = createMatrix(m, p);

    B = fillMatrixValues(B, n, m);
    C = fillMatrixValues(C, m, p);

    // Matrix-Matrix Multiplication
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            for (int k = 0; k<p; k++) {
                A[i][j] += B[i][k]*C[k][j];
            }
        }
    }

    // Print out entries of A
    cout << "Entries of B Matrix" << endl;
    printMatrixValues(B, n, m);
    cout << "Entries of C Matrix" << endl;
    printMatrixValues(C, m, p);
    cout << "Entries of A Matrix" << endl;
    printMatrixValues(A, n, p);

    return 0;
}
