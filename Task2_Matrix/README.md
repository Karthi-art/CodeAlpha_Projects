# Task 2: Matrix Operations ⭐⭐

## Overview
A comprehensive matrix operations program that implements addition, multiplication, and transpose operations on 2D arrays using modular functions.

**Difficulty Level:** Intermediate  
**Concepts:** 2D Arrays, Functions, Nested Loops, Mathematical Operations, Input Validation

---

## 📋 Project Description

This program demonstrates how to work with matrices (2D arrays) in C, implementing three fundamental matrix operations commonly used in mathematics and computer science.

---

## ✨ Features

### Matrix Operations
- **➕ Matrix Addition** - Add corresponding elements of two matrices
- **✖️ Matrix Multiplication** - Calculate dot product of matrices
- **🔄 Matrix Transpose** - Swap rows and columns

### Advanced Features
- Dimension validation for compatibility
- Error handling for impossible operations
- Formatted matrix display
- Input validation for array bounds
- Menu-driven interface

---

## 🛠️ Technical Details

### Data Structures
- **2D Arrays:** `int matrix[MAX][MAX]`
- **Matrix Dimensions:** Rows and columns stored as integers

### Key Functions

| Function | Parameters | Purpose |
|----------|-----------|---------|
| `readMatrix()` | array, rows, cols | Read matrix from user |
| `displayMatrix()` | array, rows, cols | Print formatted matrix |
| `addMatrices()` | mat1, mat2, result, rows, cols | Add two matrices |
| `multiplyMatrices()` | mat1, mat2, result, r1, c1, r2, c2 | Multiply matrices |
| `transposeMatrix()` | matrix, trans, rows, cols | Transpose matrix |

### Constants
- `MAX = 10` - Maximum matrix size (10x10)

---

## 📖 How to Use

### Compilation
```bash
gcc matrix_operations.c -o matrix
```

### Running the Program
```bash
# On Linux/macOS
./matrix

# On Windows
matrix.exe
```

### Example Usage: Matrix Addition
```
========================================
    MATRIX OPERATIONS PROGRAM
========================================

Enter your choice (1-4): 1

--- MATRIX ADDITION ---
Enter dimensions (rows cols): 2 2

Matrix 1:
Element [0][0]: 1
Element [0][1]: 2
Element [1][0]: 3
Element [1][1]: 4

Matrix 2:
Element [0][0]: 5
Element [0][1]: 6
Element [1][0]: 7
Element [1][1]: 8

=== INPUT MATRICES ===

Matrix 1:
   1    2 
   3    4 

Matrix 2:
   5    6 
   7    8 

--- Performing Matrix Addition ---
Addition completed successfully!

=== RESULT (Matrix 1 + Matrix 2) ===

Matrix (2 x 2):
   6    8 
  10   12 
```

---

## 💻 Matrix Operations Explained

### 1. Matrix Addition
```
[1 2]   [5 6]   [1+5 2+6]   [6  8]
[3 4] + [7 8] = [3+7 4+8] = [10 12]
```
- **Requirement:** Same dimensions
- **Process:** Add corresponding elements
- **Result:** Matrix with same dimensions

### 2. Matrix Multiplication
```
[1 2]   [5 6]   [1*5+2*7  1*6+2*8]   [19 22]
[3 4] × [7 8] = [3*5+4*7  3*6+4*8] = [43 50]
```
- **Requirement:** Columns of Matrix 1 = Rows of Matrix 2
- **Formula:** result[i][j] = Σ(mat1[i][k] * mat2[k][j])
- **Result Dimensions:** r1 × c2

### 3. Matrix Transpose
```
[1 2 3]       [1 4]
[4 5 6] → [2 5]
          [3 6]
```
- **Requirement:** Any dimensions
- **Process:** Swap rows and columns
- **Result Dimensions:** c × r (reversed)

---

## 🧪 Test Cases

### Test 1: Basic Addition (2×2)
```
Input:
Matrix 1: [[1, 2], [3, 4]]
Matrix 2: [[5, 6], [7, 8]]

Output:
[[6, 8], [10, 12]]
Status: ✅ PASS
```

### Test 2: Multiplication (3×2 × 2×3)
```
Input:
Matrix 1: [[1, 2], [3, 4], [5, 6]]
Matrix 2: [[1, 2, 3], [4, 5, 6]]

Output:
[[9, 12, 15], [19, 26, 33], [29, 40, 51]]
Status: ✅ PASS
```

### Test 3: Transpose (3×2)
```
Input:
Matrix: [[1, 2, 3], [4, 5, 6]]

Output:
[[1, 4], [2, 5], [3, 6]]
Status: ✅ PASS
```

### Test 4: Incompatible Multiplication Error
```
Input:
Matrix 1: 2×3
Matrix 2: 2×2

Output:
ERROR: Cannot multiply matrices!
Columns of Matrix 1 (3) must equal rows of Matrix 2 (2)
Status: ✅ PASS (Error Handling)
```

### Test 5: Zero/Identity Matrix
```
Input:
Matrix 1: [[1, 2], [3, 4]]
Matrix 2: [[1, 0], [0, 1]] (Identity Matrix)

Output:
[[1, 2], [3, 4]] (Unchanged)
Status: ✅ PASS
```

---

## 🎯 Learning Outcomes

✅ **2D Arrays** - Working with multi-dimensional arrays  
✅ **Nested Loops** - Triple nested loops for multiplication  
✅ **Functions** - Modular code with reusable functions  
✅ **Mathematical Operations** - Matrix algebra  
✅ **Input Validation** - Checking array bounds and dimensions  
✅ **Error Handling** - Preventing invalid operations  
✅ **Formatted Output** - Displaying matrices clearly  

---

## 📝 Code Structure

### Main Workflow
```
1. Display menu
2. User selects operation (1-4)
3. Get matrix dimensions
   - Validate dimensions (1 to MAX)
4. Read matrix values
5. Perform operation
   - Validate compatibility if needed
6. Display result
7. Loop until user exits (choice 4)
```

### Function Relationships
```
main()
├── displayMenu()
├── readMatrix()
├── displayMatrix()
├── addMatrices()
├── multiplyMatrices()
└── transposeMatrix()
```

---

## 🚀 Mathematical Background

### Matrix Addition Properties
```
A + B = B + A (Commutative)
(A + B) + C = A + (B + C) (Associative)
A + 0 = A (Identity element)
```

### Matrix Multiplication Properties
```
(AB)C = A(BC) (Associative)
A(B + C) = AB + AC (Distributive)
AB ≠ BA (NOT Commutative)
IA = AI = A (Identity matrix)
```

### Transpose Properties
```
(A^T)^T = A
(A + B)^T = A^T + B^T
(AB)^T = B^T A^T
(kA)^T = k(A^T)
```

---

## 🐛 Common Issues & Solutions

| Issue | Cause | Solution |
|-------|-------|----------|
| Program crashes | Array out of bounds | Check MAX constant and input dimensions |
| Wrong multiplication result | Dimension mismatch | Verify columns of mat1 = rows of mat2 |
| Transpose incorrect | Row/column swap error | Check trans[j][i] = matrix[i][j] |
| Division by zero | Not applicable | Not used in this program |
| Garbage values | Uninitialized array | Initialize result array before use |

---

## 💡 Tips for Understanding

1. **Visualize Matrices** - Draw on paper before coding
2. **Trace Through** - Follow logic step by step
3. **Test Small Cases** - Use 2×2 matrices first
4. **Print Intermediate** - Debug with extra printf statements
5. **Study Math** - Understand matrix operations mathematically

---

## 🔧 Customization Ideas

### Add More Operations
```c
// Determinant (square matrices only)
void determinant(int matrix[MAX][MAX], int n)

// Matrix inverse
void inverse(int matrix[MAX][MAX], int n)

// Scalar multiplication
void scalarMultiply(int matrix[MAX][MAX], int scalar, int rows, int cols)
```

### Improve Functionality
```c
// Save matrix to file
void saveMatrix(int matrix[MAX][MAX], int rows, int cols, char* filename)

// Load matrix from file
void loadMatrix(int matrix[MAX][MAX], int* rows, int* cols, char* filename)

// Calculate trace (sum of diagonal elements)
int calculateTrace(int matrix[MAX][MAX], int n)
```

---

## 📊 Performance Considerations

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|-------------------|
| Addition | O(m × n) | O(m × n) |
| Multiplication | O(r1 × c1 × c2) | O(r1 × c2) |
| Transpose | O(m × n) | O(m × n) |

Where m, n are dimensions of input matrices.

---

## 📚 Related Mathematics

### Matrix Concepts
- **Rows and Columns** - Matrix dimensions
- **Element** - Individual value in matrix
- **Square Matrix** - Rows = Columns
- **Identity Matrix** - Diagonal 1s, others 0
- **Zero Matrix** - All elements are 0
- **Symmetric Matrix** - A = A^T

---

## 📄 File Information

| File | Size | Purpose |
|------|------|---------|
| matrix_operations.c | ~10 KB | Main C program |
| README.md | ~10 KB | Documentation |

---

---

## ✅ Completion Checklist

- [x] Addition implementation
- [x] Multiplication with validation
- [x] Transpose implementation
- [x] Dimension checking
- [x] Error handling
- [x] Formatted output
- [x] Input validation
- [x] Menu system
- [x] Test cases
- [x] Documentation

---
