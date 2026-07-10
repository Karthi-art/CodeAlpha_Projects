# CodeAlpha C Programming Internship Projects

Welcome to my CodeAlpha C Programming Internship repository! This repository contains four progressively challenging C programming projects that demonstrate fundamental and intermediate programming concepts.

## 📋 Projects Overview

### Project 1: Simple Calculator 
A basic arithmetic calculator program that performs addition, subtraction, multiplication, and division using switch-case statements.

**Features:**
- Basic arithmetic operations
- Input validation
- Error handling for division by zero
- Loop for multiple calculations
- User-friendly interface

**Technologies:** C, Standard Library

---

### Project 2: Matrix Operations 
A program to perform mathematical operations on matrices including addition, multiplication, and transpose.

**Features:**
- Matrix addition
- Matrix multiplication with dimension validation
- Matrix transpose
- 2D array manipulation
- Function-based modular design
- Formatted output

**Technologies:** C, 2D Arrays, Functions

---

### Project 3: Student Management System 
A comprehensive menu-driven system to manage student records with persistent file storage.

**Features:**
- Add new student records
- Search students by roll number
- Update student information
- Delete student records
- Display all students
- File I/O with binary format (.dat files)
- Persistent data storage
- Structured data using C structs

**Technologies:** C, Structures, File I/O, Dynamic Data Management

---

### Project 4: Banking System Mini Project 
A full-featured banking application with account management and transaction tracking.

**Features:**
- Create bank accounts
- Deposit and withdraw funds
- Check account balance
- View transaction history
- Transaction logging with date/time
- Balance validation
- File-based persistence
- Multiple account management

**Technologies:** C, Structures, File I/O, Date/Time Handling, Advanced Data Management

## 📁 Project Structure

```
_CodeAlpha_Projects/
│
├── Task1_Calculator/
│   ├── calculator.c
│   ├── README.md
│   └── output/
│
├── Task2_Matrix/
│   ├── matrix_operations.c
│   ├── README.md
│   └── output/
│
├── Task3_StudentManagement/
│   ├── student_management.c
│   ├── students.dat (generated at runtime)
│   ├── README.md
│   └── output/
│
├── Task4_Banking/
│   ├── banking_system.c
│   ├── bank_accounts.dat (generated at runtime)
│   ├── README.md
│   └── output/
│
├── README.md (this file)
├── .gitignore
└── LICENSE
```

---

## 🚀 How to Run Each Project

### Task 1: Calculator
```bash
cd Task1_Calculator
gcc calculator.c -o calculator
./calculator          # On Linux/macOS
calculator.exe        # On Windows
```

### Task 2: Matrix Operations
```bash
cd Task2_Matrix
gcc matrix_operations.c -o matrix
./matrix
```

### Task 3: Student Management System
```bash
cd Task3_StudentManagement
gcc student_management.c -o student_mgmt
./student_mgmt
```

### Task 4: Banking System
```bash
cd Task4_Banking
gcc banking_system.c -o banking
./banking
```

---

## 📖 Key Concepts Implemented

### Fundamental Concepts
- ✅ Variables and data types
- ✅ Input/Output operations
- ✅ Control flow (if-else, switch-case)
- ✅ Loops (for, while, do-while)
- ✅ Functions and modularity
- ✅ Arrays and 2D arrays

### Intermediate Concepts
- ✅ Structures (structs)
- ✅ File I/O operations
- ✅ Binary file handling
- ✅ Dynamic data management
- ✅ Error handling
- ✅ Input validation

---

## 🧪 Testing

Each project has been tested with various scenarios:

### Calculator
- ✓ Positive and negative numbers
- ✓ Decimal numbers
- ✓ Division by zero handling
- ✓ Invalid operations

### Matrix Operations
- ✓ 2x2, 3x3, and 4x4 matrices
- ✓ Incompatible dimensions for multiplication
- ✓ Transpose for rectangular matrices
- ✓ Zero matrices

### Student Management
- ✓ Adding multiple records
- ✓ Searching existing and non-existing students
- ✓ Updating records
- ✓ Deleting records
- ✓ File persistence (close and reopen)

### Banking System
- ✓ Multiple account creation
- ✓ Deposits and withdrawals
- ✓ Insufficient balance handling
- ✓ Negative amount prevention
- ✓ Transaction history accuracy
- ✓ Data persistence

---

## 💡 Learning Outcomes

By completing these projects, you will understand:

1. **C Fundamentals**
   - Data types and operators
   - Control structures
   - Functions and scope

2. **Data Structures**
   - Arrays (1D and 2D)
   - Structures and their usage
   - Memory organization

3. **File Handling**
   - Reading and writing files
   - Binary vs text files
   - Data persistence

4. **Software Design**
   - Modular programming
   - Function decomposition
   - Error handling strategies
   - User interface design

---

## 📝 File Descriptions

Each task folder contains:

- **Source Code (.c file):** Complete, commented C program
- **README.md:** Task-specific documentation
- **output/ folder:** Sample outputs and test results
- **Data files (.dat):** Generated at runtime for Tasks 3 & 4

---

## 🐛 Troubleshooting

### Compilation Errors
| Error | Solution |
|-------|----------|
| `gcc: command not found` | Install GCC compiler |
| `undefined reference to function` | Check function definition |
| `expected ';' before '}'` | Check for missing semicolons |

### Runtime Issues
| Issue | Solution |
|-------|----------|
| Program crashes on input | Check input validation |
| File not created | Verify file permissions |
| Data not persisting | Ensure file I/O operations completed |

---

## 🎯 Completion Status

- [x] Task 1: Calculator Program
- [x] Task 2: Matrix Operations
- [x] Task 3: Student Management System
- [x] Task 4: Banking System
- [x] Documentation
- [x] Test Cases
---

## 🚀 Future Enhancements

Potential improvements for each project:

### Calculator
- [ ] Graphical User Interface (GUI)
- [ ] Scientific calculator functions
- [ ] Expression evaluation
- [ ] History of calculations

### Matrix Operations
- [ ] Matrix inversion
- [ ] Determinant calculation
- [ ] Eigenvalue computation
- [ ] Sparse matrix handling

### Student Management
- [ ] Database integration (SQLite)
- [ ] Web interface
- [ ] Advanced search filters
- [ ] Report generation

### Banking System
- [ ] Interest calculation
- [ ] Loan management
- [ ] ATM simulation
- [ ] Mobile app interface

---
**Status:** ✅ All projects completed and tested

---

Happy Coding! 🎉
