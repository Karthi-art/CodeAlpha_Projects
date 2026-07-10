/*
 * ====================================================================
 * PROJECT: Banking System Mini Project
 * DESCRIPTION: Bank Account Management System with transactions
 * LANGUAGE: C
 * ====================================================================
 * 
 * FEATURES:
 * - Create bank accounts
 * - Deposit and withdraw funds
 * - Check account balance
 * - View transaction history
 * - Transaction logging with date/time
 * - Multiple account management
 * - File-based persistence
 * - Balance validation and error handling
 * 
 * COMPILATION:
 * gcc banking_system.c -o banking
 * 
 * EXECUTION:
 * ./banking (Linux/macOS)
 * banking.exe (Windows)
 * 
 * DATA FILE: bank_accounts.dat (generated at runtime)
 * ====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 50
#define BANK_FILE "bank_accounts.dat"
#define NAME_SIZE 50
#define EMAIL_SIZE 50
#define TYPE_SIZE 10
#define DATETIME_SIZE 50

// Structure for transactions
struct Transaction {
    char type[TYPE_SIZE];           // "Deposit" or "Withdraw"
    double amount;
    char date_time[DATETIME_SIZE];
    double balance_after;
};

// Structure for bank account
struct Account {
    int account_number;
    char account_holder[NAME_SIZE];
    char email[EMAIL_SIZE];
    double balance;
    struct Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count;
};

// Function to get current date and time
void getCurrentDateTime(char *datetime) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(datetime, DATETIME_SIZE, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to display menu
void displayMenu() {
    printf("\n========================================\n");
    printf("       BANKING SYSTEM\n");
    printf("========================================\n");
    printf("1. Create New Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. View Transaction History\n");
    printf("6. View All Accounts\n");
    printf("7. Save and Exit\n");
    printf("========================================\n");
}

// Function to create new account
void createAccount(struct Account accounts[], int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("\nERROR: Bank capacity full! Maximum %d accounts\n", MAX_ACCOUNTS);
        return;
    }

    printf("\n========== CREATE NEW ACCOUNT ==========\n");
    
    accounts[*count].account_number = 1001 + *count;

    getchar(); // Clear newline
    
    printf("Enter Account Holder Name: ");
    fgets(accounts[*count].account_holder, NAME_SIZE, stdin);
    accounts[*count].account_holder[strcspn(accounts[*count].account_holder, "\n")] = 0;

    printf("Enter Email: ");
    fgets(accounts[*count].email, EMAIL_SIZE, stdin);
    accounts[*count].email[strcspn(accounts[*count].email, "\n")] = 0;

    printf("Enter Initial Deposit Amount: $");
    scanf("%lf", &accounts[*count].balance);

    if (accounts[*count].balance < 0) {
        printf("ERROR: Initial deposit cannot be negative!\n");
        return;
    }

    accounts[*count].transaction_count = 0;

    printf("\n✓ Account created successfully!\n");
    printf("Account Number: %d\n", accounts[*count].account_number);
    printf("Account Holder: %s\n", accounts[*count].account_holder);
    printf("Initial Balance: $%.2lf\n", accounts[*count].balance);

    (*count)++;
}

// Function to find account by number
int findAccount(struct Account accounts[], int count, int acc_num) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].account_number == acc_num) {
            return i;
        }
    }
    return -1;
}

// Function to deposit money
void deposit(struct Account accounts[], int count) {
    int acc_num;
    double amount;

    printf("\n========== DEPOSIT ==========\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);

    int index = findAccount(accounts, count, acc_num);
    if (index == -1) {
        printf("ERROR: Account not found!\n");
        return;
    }

    printf("\nAccount Holder: %s\n", accounts[index].account_holder);
    printf("Current Balance: $%.2lf\n", accounts[index].balance);
    printf("Enter amount to deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("ERROR: Deposit amount must be positive!\n");
        return;
    }

    accounts[index].balance += amount;

    // Record transaction
    if (accounts[index].transaction_count < MAX_TRANSACTIONS) {
        strcpy(accounts[index].transactions[accounts[index].transaction_count].type, "Deposit");
        accounts[index].transactions[accounts[index].transaction_count].amount = amount;
        getCurrentDateTime(accounts[index].transactions[accounts[index].transaction_count].date_time);
        accounts[index].transactions[accounts[index].transaction_count].balance_after = accounts[index].balance;
        accounts[index].transaction_count++;
    }

    printf("\n✓ Deposit successful!\n");
    printf("Amount Deposited: $%.2lf\n", amount);
    printf("New Balance: $%.2lf\n", accounts[index].balance);
}

// Function to withdraw money
void withdraw(struct Account accounts[], int count) {
    int acc_num;
    double amount;

    printf("\n========== WITHDRAW ==========\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);

    int index = findAccount(accounts, count, acc_num);
    if (index == -1) {
        printf("ERROR: Account not found!\n");
        return;
    }

    printf("\nAccount Holder: %s\n", accounts[index].account_holder);
    printf("Current Balance: $%.2lf\n", accounts[index].balance);
    printf("Enter amount to withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("ERROR: Withdrawal amount must be positive!\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("ERROR: Insufficient balance!\n");
        printf("Available Balance: $%.2lf\n", accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;

    // Record transaction
    if (accounts[index].transaction_count < MAX_TRANSACTIONS) {
        strcpy(accounts[index].transactions[accounts[index].transaction_count].type, "Withdraw");
        accounts[index].transactions[accounts[index].transaction_count].amount = amount;
        getCurrentDateTime(accounts[index].transactions[accounts[index].transaction_count].date_time);
        accounts[index].transactions[accounts[index].transaction_count].balance_after = accounts[index].balance;
        accounts[index].transaction_count++;
    }

    printf("\n✓ Withdrawal successful!\n");
    printf("Amount Withdrawn: $%.2lf\n", amount);
    printf("New Balance: $%.2lf\n", accounts[index].balance);
}

// Function to check balance
void checkBalance(struct Account accounts[], int count) {
    int acc_num;
    printf("\n========== CHECK BALANCE ==========\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);

    int index = findAccount(accounts, count, acc_num);
    if (index == -1) {
        printf("ERROR: Account not found!\n");
        return;
    }

    printf("\n--- Account Information ---\n");
    printf("Account Number: %d\n", accounts[index].account_number);
    printf("Account Holder: %s\n", accounts[index].account_holder);
    printf("Email: %s\n", accounts[index].email);
    printf("Current Balance: $%.2lf\n", accounts[index].balance);
    printf("Total Transactions: %d\n", accounts[index].transaction_count);
}

// Function to view transaction history
void viewTransactionHistory(struct Account accounts[], int count) {
    int acc_num;
    printf("\n========== TRANSACTION HISTORY ==========\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);

    int index = findAccount(accounts, count, acc_num);
    if (index == -1) {
        printf("ERROR: Account not found!\n");
        return;
    }

    printf("\nAccount Holder: %s\n", accounts[index].account_holder);

    if (accounts[index].transaction_count == 0) {
        printf("No transactions yet!\n");
        return;
    }

    printf("\n%-12s %-12s %-20s %-15s\n", "Type", "Amount", "Date & Time", "Balance");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < accounts[index].transaction_count; i++) {
        printf("%-12s $%-11.2lf %-20s $%-14.2lf\n",
               accounts[index].transactions[i].type,
               accounts[index].transactions[i].amount,
               accounts[index].transactions[i].date_time,
               accounts[index].transactions[i].balance_after);
    }
    printf("---------------------------------------------------\n");
    printf("Total Transactions: %d\n", accounts[index].transaction_count);
}

// Function to view all accounts
void viewAllAccounts(struct Account accounts[], int count) {
    if (count == 0) {
        printf("\n⚠ No accounts in the bank!\n");
        return;
    }

    printf("\n========== ALL BANK ACCOUNTS ==========\n");
    printf("%-10s %-20s %-25s %-15s\n", "Acc No", "Holder Name", "Email", "Balance");
    printf("-----------------------------------------------------------\n");

    double total_balance = 0;
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-25s $%-14.2lf\n",
               accounts[i].account_number,
               accounts[i].account_holder,
               accounts[i].email,
               accounts[i].balance);
        total_balance += accounts[i].balance;
    }
    printf("-----------------------------------------------------------\n");
    printf("Total Accounts: %d\n", count);
    printf("Total Bank Balance: $%.2lf\n", total_balance);
}

// Function to save data to file
void saveBankData(struct Account accounts[], int count) {
    FILE *file = fopen(BANK_FILE, "wb");
    if (file == NULL) {
        printf("\nERROR: Cannot open file for writing!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(accounts, sizeof(struct Account), count, file);
    fclose(file);

    printf("\n✓ Data saved successfully!\n");
    printf("File: %s\n", BANK_FILE);
    printf("Accounts saved: %d\n", count);
}

// Function to load data from file
void loadBankData(struct Account accounts[], int *count) {
    FILE *file = fopen(BANK_FILE, "rb");
    if (file == NULL) {
        printf("No existing data. Starting fresh bank session.\n");
        *count = 0;
        return;
    }

    fread(count, sizeof(int), 1, file);
    fread(accounts, sizeof(struct Account), *count, file);
    fclose(file);

    printf("✓ Data loaded successfully!\n");
    printf("Accounts loaded: %d\n", *count);
}

// Main function
int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

    printf("\n");
    printf("    ╔═══════════════════════════════════════╗\n");
    printf("    ║  BANKING SYSTEM MANAGEMENT           ║\n");
    printf("    ║  CodeAlpha Internship Project        ║\n");
    printf("    ╚═══════════════════════════════════════╝\n");

    loadBankData(accounts, &count);

    do {
        displayMenu();
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &count);
                break;

            case 2:
                deposit(accounts, count);
                break;

            case 3:
                withdraw(accounts, count);
                break;

            case 4:
                checkBalance(accounts, count);
                break;

            case 5:
                viewTransactionHistory(accounts, count);
                break;

            case 6:
                viewAllAccounts(accounts, count);
                break;

            case 7:
                saveBankData(accounts, count);
                printf("\nThank you for using our Banking System!\n");
                printf("Goodbye! 👋\n\n");
                break;

            default:
                printf("\nERROR: Invalid choice! Please enter 1 to 7.\n");
        }
    } while (choice != 7);

    return 0;
}

/*
 * ====================================================================
 * TEST CASES:
 * ====================================================================
 * 
 * TEST 1: Create Accounts
 * Create 3 accounts with different details
 * Verify: Accounts created with unique numbers
 * 
 * TEST 2: Deposit Valid Amount
 * Deposit $500 to account
 * Verify: Balance increased, transaction recorded
 * 
 * TEST 3: Deposit Negative Amount
 * Try to deposit -$100
 * Verify: Error message shown
 * 
 * TEST 4: Withdraw Valid Amount
 * Withdraw $200 from $500 balance
 * Verify: Balance=$300, transaction recorded
 * 
 * TEST 5: Withdraw Insufficient Balance
 * Try to withdraw $1000 from $300 balance
 * Verify: Error message shown
 * 
 * TEST 6: Check Balance
 * Check balance of created account
 * Verify: Correct balance displayed
 * 
 * TEST 7: View Transaction History
 * View history after multiple operations
 * Verify: All transactions with timestamps
 * 
 * TEST 8: View All Accounts
 * Display all created accounts
 * Verify: All accounts shown with balances
 * 
 * TEST 9: File Persistence
 * Save, close, reopen program
 * Verify: Data loaded correctly
 * 
 * ====================================================================
 */
