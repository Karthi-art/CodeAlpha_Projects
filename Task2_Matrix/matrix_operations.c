#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to read matrix from user
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nEnter matrix elements (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nMatrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], 
                 int result[MAX][MAX], int rows, int cols) {
    printf("\n--- Performing Matrix Addition ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("Addition completed successfully!\n");
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], 
                      int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    
    // Validate dimensions
    if (c1 != r2) {
        printf("\nERROR: Cannot multiply matrices!\n");
        printf("Columns of Matrix 1 (%d) must equal rows of Matrix 2 (%d)\n", c1, r2);
        return;
    }
    
    printf("\n--- Performing Matrix Multiplication ---\n");
    
    // Initialize result matrix with zeros
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    
    // Multiplication logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("Multiplication completed successfully!\n");
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int trans[MAX][MAX], 
                     int rows, int cols) {
    printf("\n--- Performing Matrix Transpose ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = matrix[i][j];
        }
    }
    printf("Transpose completed successfully!\n");
}

// Function to display menu
void displayMenu() {
    printf("\n========================================\n");
    printf("    MATRIX OPERATIONS PROGRAM\n");
    printf("========================================\n");
    printf("Select an operation:\n");
    printf("  1: Matrix Addition\n");
    printf("  2: Matrix Multiplication\n");
    printf("  3: Matrix Transpose\n");
    printf("  4: Exit\n");
    printf("========================================\n");
}

// Main function
int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX];
    int result[MAX][MAX], trans[MAX][MAX];
    int rows, cols, choice;
    int r1, c1, r2, c2;

    printf("\n");
    printf("    ╔═══════════════════════════════════════╗\n");
    printf("    ║  WELCOME TO MATRIX OPERATIONS        ║\n");
    printf("    ║  CodeAlpha Internship Project        ║\n");
    printf("    ╚═══════════════════════════════════════╝\n");

    while (1) {
        displayMenu();
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Matrix Addition
                printf("\n--- MATRIX ADDITION ---\n");
                printf("Enter dimensions (rows cols): ");
                scanf("%d %d", &rows, &cols);

                // Validate dimensions
                if (rows <= 0 || rows > MAX || cols <= 0 || cols > MAX) {
                    printf("ERROR: Invalid dimensions! Use 1 to %d\n", MAX);
                    break;
                }

                printf("\nMatrix 1:");
                readMatrix(mat1, rows, cols);

                printf("\nMatrix 2:");
                readMatrix(mat2, rows, cols);

                printf("\n=== INPUT MATRICES ===");
                printf("\nMatrix 1:");
                displayMatrix(mat1, rows, cols);
                printf("\nMatrix 2:");
                displayMatrix(mat2, rows, cols);

                addMatrices(mat1, mat2, result, rows, cols);

                printf("\n=== RESULT (Matrix 1 + Matrix 2) ===");
                displayMatrix(result, rows, cols);
                break;

            case 2:
                // Matrix Multiplication
                printf("\n--- MATRIX MULTIPLICATION ---\n");
                printf("Enter dimensions of Matrix 1 (rows cols): ");
                scanf("%d %d", &r1, &c1);

                // Validate dimensions
                if (r1 <= 0 || r1 > MAX || c1 <= 0 || c1 > MAX) {
                    printf("ERROR: Invalid dimensions! Use 1 to %d\n", MAX);
                    break;
                }

                printf("Enter dimensions of Matrix 2 (rows cols): ");
                scanf("%d %d", &r2, &c2);

                // Validate dimensions
                if (r2 <= 0 || r2 > MAX || c2 <= 0 || c2 > MAX) {
                    printf("ERROR: Invalid dimensions! Use 1 to %d\n", MAX);
                    break;
                }

                // Check if multiplication is possible
                if (c1 != r2) {
                    printf("\nERROR: Cannot multiply matrices!\n");
                    printf("Columns of Matrix 1 (%d) must equal rows of Matrix 2 (%d)\n", c1, r2);
                    break;
                }

                printf("\nMatrix 1:");
                readMatrix(mat1, r1, c1);

                printf("\nMatrix 2:");
                readMatrix(mat2, r2, c2);

                printf("\n=== INPUT MATRICES ===");
                printf("\nMatrix 1 (%d x %d):", r1, c1);
                displayMatrix(mat1, r1, c1);
                printf("\nMatrix 2 (%d x %d):", r2, c2);
                displayMatrix(mat2, r2, c2);

                multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);

                printf("\n=== RESULT (Matrix 1 × Matrix 2) ===");
                displayMatrix(result, r1, c2);
                break;

            case 3:
                // Matrix Transpose
                printf("\n--- MATRIX TRANSPOSE ---\n");
                printf("Enter dimensions (rows cols): ");
                scanf("%d %d", &rows, &cols);

                // Validate dimensions
                if (rows <= 0 || rows > MAX || cols <= 0 || cols > MAX) {
                    printf("ERROR: Invalid dimensions! Use 1 to %d\n", MAX);
                    break;
                }

                printf("\nMatrix:");
                readMatrix(mat1, rows, cols);

                printf("\n=== ORIGINAL MATRIX ===");
                displayMatrix(mat1, rows, cols);

                transposeMatrix(mat1, trans, rows, cols);

                printf("\n=== TRANSPOSED MATRIX (%d x %d) ===", cols, rows);
                displayMatrix(trans, cols, rows);
                break;

            case 4:
                printf("\n");
                printf("Thank you for using Matrix Operations!\n");
                printf("Goodbye! 👋\n\n");
                return 0;

            default:
                printf("\nERROR: Invalid choice! Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}

/*
 * ====================================================================
 * TEST CASES:
 * ====================================================================
 * 
 * TEST 1: Matrix Addition (2x2)
 * Matrix 1:     Matrix 2:     Result:
 * 1  2          5  6          6  8
 * 3  4          7  8          10 12
 * 
 * TEST 2: Matrix Multiplication (2x2 × 2x2)
 * Matrix 1:     Matrix 2:     Result:
 * 1  2          5  6          19 22
 * 3  4          7  8          43 50
 * 
 * TEST 3: Matrix Transpose (2x3)
 * Original:            Transposed (3x2):
 * 1 2 3                1 4
 * 4 5 6                2 5
 *                      3 6
 * 
 * TEST 4: Incompatible Multiplication
 * Matrix 1: 2x3        Matrix 2: 2x2
 * Result: ERROR - Cannot multiply
 * 
 * TEST 5: Identity Matrix Multiplication
 * Matrix 1: [[1,2],[3,4]]  Matrix 2: [[1,0],[0,1]]
 * Result: [[1,2],[3,4]] (unchanged)
 * 
 * ====================================================================
 */
