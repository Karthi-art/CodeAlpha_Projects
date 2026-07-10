# Task 1: Simple Calculator Program ⭐

## Overview
A basic arithmetic calculator that performs fundamental mathematical operations using C language and switch-case statements.

**Difficulty Level:** Beginner  
**Concepts:** Variables, Input/Output, Control Flow (switch-case), Functions, Loops

---

## 📋 Project Description

This calculator program allows users to perform basic arithmetic operations on two numbers. It demonstrates fundamental programming concepts and best practices in C, including error handling and user input validation.

---

## ✨ Features

- **Arithmetic Operations:**
  - ➕ Addition
  - ➖ Subtraction
  - ✖️ Multiplication
  - ➗ Division

- **Error Handling:**
  - Division by zero prevention
  - Invalid operation detection
  - Invalid input validation

- **User Experience:**
  - Menu-driven interface
  - Multiple calculations without restarting
  - Clear output formatting
  - Helpful error messages

---

## 🛠️ Technical Details

### Data Types Used
- `float` - For storing numbers (supports decimals)
- `char` - For storing operations and user choices

### Control Structures
- `while` loop - For multiple calculations
- `switch-case` - For operation selection
- `if-else` - For input validation

### Functions
- `displayMenu()` - Shows calculator menu
- `add()` - Performs addition
- `subtract()` - Performs subtraction
- `multiply()` - Performs multiplication
- `divide()` - Performs division with validation
- `main()` - Main program logic

---

## 📖 How to Use

### Compilation
```bash
gcc calculator.c -o calculator
```

### Running the Program
```bash
# On Linux/macOS
./calculator

# On Windows
calculator.exe
```

### Example Usage
```
=========================================
    SIMPLE CALCULATOR PROGRAM
=========================================

Enter first number: 10
Enter operation (+, -, *, /): +
Enter second number: 5

Result: 10.00 + 5.00 = 15.00

Do you want to perform another calculation? (y/n): y
```

---

## 💻 Code Structure

### Main Workflow
```
1. Display welcome message
2. Loop:
   a. Show menu options
   b. Get first number
   c. Get operation
   d. Get second number
   e. Perform calculation based on switch-case
   f. Display result
   g. Ask to continue
3. Exit when user chooses to quit
```

### Function Breakdown

**displayMenu()**
- Prints the calculator menu
- Shows available operations

**add(num1, num2)**
- Adds two numbers
- Prints formatted result

**subtract(num1, num2)**
- Subtracts num2 from num1
- Prints formatted result

**multiply(num1, num2)**
- Multiplies two numbers
- Prints formatted result

**divide(num1, num2)**
- Divides num1 by num2
- Checks for division by zero
- Prints formatted result or error message

**main()**
- Manages program flow
- Handles user input
- Controls loops

---

## 🧪 Test Cases

| Test # | Input | Expected Output | Status |
|--------|-------|-----------------|--------|
| 1 | 5 + 3 | 5.00 + 3.00 = 8.00 | ✅ |
| 2 | 10 - 3 | 10.00 - 3.00 = 7.00 | ✅ |
| 3 | 4 * 5 | 4.00 * 5.00 = 20.00 | ✅ |
| 4 | 20 / 4 | 20.00 / 4.00 = 5.00 | ✅ |
| 5 | 10 / 0 | ERROR: Cannot divide by zero! | ✅ |
| 6 | 5.5 + 2.3 | 5.50 + 2.30 = 7.80 | ✅ |
| 7 | -5 * -3 | -5.00 * -3.00 = 15.00 | ✅ |
| 8 | 100 / 3 | 100.00 / 3.00 = 33.33 | ✅ |
| 9 | Invalid op | ERROR: Invalid operation | ✅ |
| 10 | Quit (q) | Exits program | ✅ |

---

## 🎯 Learning Outcomes

After completing this project, you will understand:

✅ **Variables and Data Types** - Using `float` and `char`  
✅ **Input/Output Operations** - `scanf()` and `printf()`  
✅ **Control Flow** - Switch-case statements  
✅ **Functions** - Creating and calling functions  
✅ **Loops** - While loops for repeated execution  
✅ **Error Handling** - Validating user input  
✅ **Formatting Output** - Using format specifiers  

---

## 📝 Key Concepts Explained

### Switch-Case Statement
```c
switch(operation) {
    case '+':
        add(num1, num2);
        break;
    case '-':
        subtract(num1, num2);
        break;
    // ... more cases
    default:
        printf("Invalid operation\n");
}
```
- Checks the value of `operation`
- Executes matching case
- `default` handles invalid input
- `break` prevents fall-through

### Input Validation
```c
if (scanf("%f", &num1) != 1) {
    printf("ERROR: Invalid input!\n");
    while (getchar() != '\n');  // Clear buffer
    continue;
}
```
- Checks if input was read successfully
- Clears input buffer on error
- Prevents program crash

### Function Modularity
```c
void add(float num1, float num2) {
    printf("Result: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
}
```
- Separates logic into functions
- Makes code more readable
- Easier to maintain and debug

---

## 🚀 Possible Enhancements

Future improvements you could add:

1. **Advanced Operations**
   - Modulo (%)
   - Power (^)
   - Square root (√)

2. **Scientific Functions**
   - Trigonometric functions (sin, cos, tan)
   - Logarithmic functions
   - Factorial

3. **User Interface**
   - Graphical interface (using a GUI library)
   - Keyboard shortcuts
   - History of calculations

4. **Features**
   - Save calculations to file
   - Calculate percentage
   - Unit conversions

---

## 🐛 Common Issues & Solutions

| Issue | Cause | Solution |
|-------|-------|----------|
| Program crashes on input | Invalid input format | Check input validation |
| Newline character stuck | Input buffer not cleared | Use `while(getchar() != '\n')` |
| Wrong result | Order of operations | Check switch-case logic |
| Division shows 0 | Integer division | Use `float` instead of `int` |

---

## 📊 Program Output Example

```
╔═══════════════════════════════════════╗
║   WELCOME TO SIMPLE CALCULATOR        ║
║   CodeAlpha Internship Project        ║
╚═══════════════════════════════════════╝

========================================
    SIMPLE CALCULATOR PROGRAM
========================================
Select an operation:
  + : Addition
  - : Subtraction
  * : Multiplication
  / : Division
  q : Quit
========================================

Enter first number: 15.5
Enter operation (+, -, *, /): +
Enter second number: 8.3

Result: 15.50 + 8.30 = 23.80

Do you want to perform another calculation? (y/n): n

Thank you for using the calculator!
Goodbye! 👋
```

---

## 💡 Tips for Using This Code

1. **Modify the operations** - Try changing how calculations are done
2. **Add new functions** - Extend with more mathematical operations
3. **Experiment with loops** - Try different loop conditions
4. **Test edge cases** - Try very large numbers, negative numbers, decimals
5. **Improve formatting** - Add more visual elements to the output

---

## 📚 Related Concepts to Learn

- **Operators in C** - Arithmetic operators (+, -, *, /)
- **Format Specifiers** - %f (float), %d (int), %c (char)
- **Input Functions** - scanf(), getchar()
- **Output Functions** - printf()
- **Control Flow** - if-else, switch-case, loops

---

## ✅ Completion Checklist

- [x] Code compiles without errors
- [x] Program runs without crashes
- [x] All operations work correctly
- [x] Error handling implemented
- [x] User input validated
- [x] Output is formatted nicely
- [x] Code is well-commented
- [x] Test cases passed
- [x] Documentation complete

---

## 📄 File Information

| File | Size | Purpose |
|------|------|---------|
| calculator.c | ~7 KB | Main C program |
| README.md | ~8 KB | Documentation |

---
