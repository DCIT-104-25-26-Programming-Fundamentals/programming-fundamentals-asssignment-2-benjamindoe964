// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to input a matrix
void inputMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose a matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}

// Part B: Add two matrices
void addMatrices(int matrix1[10][10], int matrix2[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}

// Part C: Multiply two matrices
void multiplyMatrices(int matrix1[10][10], int matrix2[10][10],
                      int rows1, int cols1, int cols2)
{
    int product[10][10];

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            product[i][j] = 0;

            for (int k = 0; k < cols1; k++)
            {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "\nProduct of Matrices:\n";
    displayMatrix(product, rows1, cols2);
}

int main()
{
    int choice;

    cout << "Matrix Operations Menu\n";
    cout << "1. Transpose a Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int matrix[10][10];
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> cols;

        inputMatrix(matrix, rows, cols);

        cout << "\nOriginal Matrix:\n";
        displayMatrix(matrix, rows, cols);

        transposeMatrix(matrix, rows, cols);
    }
    else if (choice == 2)
    {
        int matrix1[10][10], matrix2[10][10];
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter first matrix:\n";
        inputMatrix(matrix1, rows, cols);

        cout << "\nEnter second matrix:\n";
        inputMatrix(matrix2, rows, cols);

        addMatrices(matrix1, matrix2, rows, cols);
    }
    else if (choice == 3)
    {
        int matrix1[10][10], matrix2[10][10];
        int rows1, cols1, rows2, cols2;

        cout << "Enter rows of first matrix: ";
        cin >> rows1;

        cout << "Enter columns of first matrix: ";
        cin >> cols1;

        cout << "Enter rows of second matrix: ";
        cin >> rows2;

        cout << "Enter columns of second matrix: ";
        cin >> cols2;

        if (cols1 != rows2)
        {
            cout << "Matrix multiplication is not possible." << endl;
            return 0;
        }

        cout << "\nEnter first matrix:\n";
        inputMatrix(matrix1, rows1, cols1);

        cout << "\nEnter second matrix:\n";
        inputMatrix(matrix2, rows2, cols2);

        multiplyMatrices(matrix1, matrix2, rows1, cols1, cols2);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

