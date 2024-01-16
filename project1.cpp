// Project 1 - Matrix Multiplication

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

 int main(){
    // Define number of rows and columns
    const int row1 = 10;
    const int column1 = row1;
    const int row2 = column1;
    const int column2 = row2;
    
    // Define matrices: A * B = C
    float matrix_A[row1][column1];
    float matrix_B[row2][column2];
    float matric_C[row1][column2] = { 0 }; // Initialize all elements to zero

    // Initialize the elements of matrix_A with random values between 0 and 10
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            matrix_A[i][j] = static_cast<float>(std::rand()) / RAND_MAX * 10.0;
        }
    }
    
    // Display the randomly initialized matrix
    std::cout << "Randomly Initialized Matrix:" << std::endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            std::cout << matrix_A[i][j] << " ";
        }
        std::cout << std::endl;
    }
 }