# Task 4: Banking System Mini Project 
## Overview
A full-featured banking system demonstrating advanced C programming concepts including structures, file I/O, transaction tracking, and complex data management.

**Difficulty Level:** Advanced  
**Concepts:** Structures, File I/O, Nested Arrays, Date/Time, Transaction Logging, Complex Data Management

---

## 📋 Project Description

This banking system simulates real-world banking operations, allowing multiple users to manage accounts with full transaction history, balance tracking, and persistent data storage.

---

## ✨ Features

### Core Banking Operations
- **🏦 Create Accounts** - Open new bank accounts with initial deposits
- **💰 Deposit Funds** - Add money to accounts
- **💸 Withdraw Funds** - Remove money with balance validation
- **💳 Check Balance** - View current account balance
- **📊 Transaction History** - View all operations with timestamps
- **🏛️ View All Accounts** - See complete bank overview

### Advanced Features
- Automatic account number generation
- Real-time date/time stamping
- Transaction logging with detailed records
- Multiple account management
- Balance validation and error handling
- Persistent data storage (binary file)
- Professional formatted output
- Financial calculations

---

## 🛠️ Technical Details

### Data Structures

#### Transaction Structure
```c
struct Transaction {
    char type[10];              // "Deposit" or "Withdraw"
    double amount;              // Transaction amount
    char date_time[50];         // Timestamp
    double balance_after;       // Balance after transaction
};
```

#### Account Structure
```c
struct Account {
    int account_number;
    char account_holder[50];
    char email[50];
    double balance;
    struct Transaction transactions[50];
    int transaction_count;
};
```

### Constants
```c
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 50
#define BANK_FILE "bank_accounts.dat"
```

### File System
- **Format:** Binary (.dat)
- **Storage:** Account count + Account records
- **Persistence:** Data saved between sessions

---

## 📖 How to Use

### Compilation
```bash
gcc banking_system.c -o banking
```

### Running the Program
```bash
# On Linux/macOS
./banking

# On Windows
banking.exe
```

### Example Workflow

#### 1. Create Account
```
Enter your choice (1-7): 1

========== CREATE NEW ACCOUNT ==========
Enter Account Holder Name: John Doe
Enter Email: john@example.com
Enter Initial Deposit Amount: $5000

✓ Account created successfully!
Account Number: 1001
Account Holder: John Doe
Initial Balance: $5000.00
```

#### 2. Deposit Money
```
Enter your choice (1-7): 2

========== DEPOSIT ==========
Enter Account Number: 1001

Account Holder: John Doe
Current Balance: $5000.00
Enter amount to deposit: $1500

✓ Deposit successful!
Amount Deposited: $1500.00
New Balance: $6500.00
```

#### 3. Withdraw Money
```
Enter your choice (1-7): 3

========== WITHDRAW ==========
Enter Account Number: 1001

Account Holder: John Doe
Current Balance: $6500.00
Enter amount to withdraw: $1000

✓ Withdrawal successful!
Amount Withdrawn: $1000.00
New Balance: $5500.00
```

#### 4. Check Balance
```
Enter your choice (1-7): 4

========== CHECK BALANCE ==========
Enter Account Number: 1001

--- Account Information ---
Account Number: 1001
Account Holder: John Doe
Email: john@example.com
Current Balance: $5500.00
Total Transactions: 2
```

#### 5. View Transaction History
```
Enter your choice (1-7): 5

========== TRANSACTION HISTORY ==========
Enter Account Number: 1001

Account Holder: John Doe

Type         Amount       Date & Time          Balance
---------------------------------------------------
Deposit      $1500.00     2026-07-10 14:25:30  $6500.00
Withdraw     $1000.00     2026-07-10 14:26:45  $5500.00
---------------------------------------------------
Total Transactions: 2
```

#### 6. View All Accounts
```
Enter your choice (1-7): 6

========== ALL BANK ACCOUNTS ==========
Acc No     Holder Name          Email                    Balance
-----------------------------------------------------------
1001       John Doe             john@example.com         $5500.00
1002       Jane Smith           jane@example.com         $8000.00
-----------------------------------------------------------
Total Accounts: 2
Total Bank Balance: $13500.00
```

#### 7. Save and Exit
```
Enter your choice (1-7): 7

✓ Data saved successfully!
File: bank_accounts.dat
Accounts saved: 2

Thank you for using our Banking System!
Goodbye! 👋
```

---

## 💻 Core Functions

### Function Reference

| Function | Purpose |
|----------|---------|
| `createAccount()` | Create new bank account |
| `deposit()` | Add funds to account |
| `withdraw()` | Remove funds with validation |
| `checkBalance()` | Display current balance |
| `viewTransactionHistory()` | Show all transactions |
| `viewAllAccounts()` | Display all bank accounts |
| `findAccount()` | Locate account by number |
| `getCurrentDateTime()` | Get timestamp |
| `saveBankData()` | Persist data to file |
| `loadBankData()` | Load data from file |

---

## 📝 Code Architecture

### Program Flow
```
1. Load data from file (if exists)
2. Display welcome message
3. Loop:
   a. Show menu
   b. Get user choice
   c. Execute operation
   d. Display results
4. On exit:
   a. Save all data
   b. Exit program
```

### Transaction Flow
```
User Input
    ↓
Validate Account
    ↓
Validate Amount
    ↓
Update Balance
    ↓
Record Transaction
    ↓
Display Confirmation
```

---

## 🧪 Test Cases

| Test # | Operation | Expected Result | Status |
|--------|-----------|-----------------|--------|
| 1 | Create valid account | Account created with unique number | ✅ |
| 2 | Create multiple accounts | All accounts created separately | ✅ |
| 3 | Deposit valid amount | Balance increased, transaction logged | ✅ |
| 4 | Deposit negative | Error message shown | ✅ |
| 5 | Withdraw valid amount | Balance decreased, transaction logged | ✅ |
| 6 | Withdraw > balance | Error, transaction denied | ✅ |
| 7 | Withdraw zero amount | Error message shown | ✅ |
| 8 | Check existing account | Balance displayed correctly | ✅ |
| 9 | Check non-existent account | Error message shown | ✅ |
| 10 | View transaction history | All transactions with timestamps | ✅ |
| 11 | View all accounts | Summary of all accounts | ✅ |
| 12 | File persistence | Data survives program restart | ✅ |

---

## 🎯 Learning Outcomes

✅ **Nested Structures** - Arrays of structures with embedded structures  
✅ **Date/Time Handling** - Using time.h for timestamps  
✅ **Transaction Logging** - Recording operations with metadata  
✅ **Financial Calculations** - Balance management and validation  
✅ **Complex File I/O** - Saving/loading structured data  
✅ **Error Handling** - Balance checks, validation  
✅ **Real-World Concepts** - Banking operations simulation  
✅ **Data Integrity** - Ensuring accurate records  

---

## 💳 Banking Concepts Implemented

### Account Management
- Unique account numbers
- Multiple accounts per bank
- Account holder information
- Email tracking

### Transaction Management
- Transaction type (Deposit/Withdraw)
- Transaction amount
- Timestamp logging
- Balance after transaction

### Balance Management
- Current balance tracking
- Insufficient balance prevention
- Real-time updates
- Transaction-based calculation

### Data Persistence
- Binary file storage
- Session-based loading
- Data integrity validation

---

## 📊 Data Flow Diagram

```
Program Start
    ↓
Load Bank Data
    ↓
Display Menu
    ↓
User Selection
├─→ Create Account ──→ Update Account Array
├─→ Deposit ──────────→ Update Balance + Log Transaction
├─→ Withdraw ─────────→ Validate + Update Balance + Log
├─→ Check Balance ────→ Display Balance Info
├─→ View History ─────→ Show All Transactions
├─→ View All ─────────→ Bank Summary
└─→ Save & Exit ──────→ Persist Data + End

```

---

## 🔐 Validation Rules

### Account Creation
- Account number: Auto-generated (1001+)
- Name: Non-empty string
- Email: String format
- Initial deposit: Non-negative

### Deposit
- Account: Must exist
- Amount: Must be positive
- Balance: Updated immediately

### Withdrawal
- Account: Must exist
- Amount: Must be positive
- Balance: Must be sufficient
- Transaction: Logged on success

---

## 🚀 Enhancement Ideas

### Advanced Features
```c
// Interest calculation
void calculateInterest(struct Account[], int)

// Account freeze/block
void freezeAccount(struct Account[], int)

// Minimum balance checking
void checkMinimumBalance(struct Account[], int)

// Fund transfer between accounts
void transferFunds(struct Account[], int, int, double)

// Monthly statements
void generateStatement(struct Account[], int)

// Account statements export to file
void exportStatement(struct Account[], int)
```

---

## 💡 Best Practices Demonstrated

✅ **Input Validation** - Check all user inputs  
✅ **Error Handling** - Graceful failure messages  
✅ **Data Integrity** - Prevent invalid operations  
✅ **Timestamp Logging** - Track all transactions  
✅ **File Management** - Proper file operations  
✅ **Code Organization** - Modular functions  
✅ **Professional Output** - Formatted displays  

---

## 📈 Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Create Account | O(1) | O(1) |
| Deposit | O(1) | O(1) |
| Withdraw | O(1) | O(1) |
| Check Balance | O(n) | O(1) |
| View History | O(n) | O(1) |
| View All | O(n) | O(1) |
| Save/Load | O(n) | O(n) |

Where n = number of accounts

---

## 🐛 Common Issues & Solutions

| Issue | Cause | Solution |
|-------|-------|----------|
| Account not found | Wrong account number | Verify account exists |
| Balance shows 0 | First time, no file | Create account and deposit |
| Transactions missing | Program closed without saving | Use "Save and Exit" |
| Negative balance | Logic error | Check validation |
| Corrupted data | File format issue | Delete .dat and restart |

---

## 🔗 Resources

- [C File I/O](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)
- [C Structures](https://www.tutorialspoint.com/cprogramming/c_structures.htm)
- [Date/Time in C](https://www.cplusplus.com/reference/ctime/)
- [Binary Files](https://www.geeksforgeeks.org/binary-files-c/)

---

## 📄 File Information

| File | Size | Purpose |
|------|------|---------|
| banking_system.c | ~15 KB | Main program |
| README.md | ~14 KB | Documentation |
| bank_accounts.dat | Variable | Account data |

---

## ✅ Completion Checklist

- [x] Account creation
- [x] Deposit functionality
- [x] Withdraw functionality
- [x] Balance checking
- [x] Transaction history
- [x] All accounts view
- [x] Date/time logging
- [x] File I/O
- [x] Input validation
- [x] Error handling
- [x] Data persistence
- [x] Documentation

---
