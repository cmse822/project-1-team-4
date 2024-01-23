// Project 1 - Matrix Multiplication
//
#include <iostream>
#include <sys/time.h>
#include <fstream>

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

void get_walltime_(double* wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
}

void get_walltime(double* wcTime) {
    get_walltime_(wcTime);
}

int main() {

    std::ofstream outputFile("runtime25.txt", std::ios::app);

    /*
    Program to perform Matrix-Matrix Multiplication
    A = BC

    */

    int n = 25; // # Rows of B
    int m = n; // # Columns of B & # Rows of C
    int p = n; // # Coulmns of C

    float** A = createMatrix(n, p);
    float** B = createMatrix(n, m);
    float** C = createMatrix(m, p);

    B = fillMatrixValues(B, n, m);
    C = fillMatrixValues(C, m, p);

    double startTime, endTime;
    get_walltime(&startTime);

    // Matrix-Matrix Multiplication
    
    
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                for (int k = 0; k<p; k++) {
                A[i][j] += B[i][k]*C[k][j];
            }
        }
    }

    get_walltime(&endTime);

    // Append content to the file
    outputFile << (endTime - startTime) << std::endl;

    // Close the file
    outputFile.close();

    //Dan - Commenting this out for speed purposes 
    
    // Print out entries of A
    // cout << "Entries of B Matrix" << endl;
    // printMatrixValues(B, n, m);
    // cout << "Entries of C Matrix" << endl;
    // printMatrixValues(C, m, p);
    // cout << "Entries of A Matrix" << endl;
    // printMatrixValues(A, n, p);

    cout << "Time taken for matrix multiplication: " << (endTime - startTime) << " seconds." << endl;



    return 0;
}
