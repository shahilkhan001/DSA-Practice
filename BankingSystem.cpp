/*
 * Banking System in C++
 * This program simulates a simple banking system with features such as:
 * - Creating a new account
 * - Depositing money into an account
 * - Withdrawing money from an account
 *
 * The system uses two classes:
 * 1. Account: Represents a bank account with details such as account number, account holder's name, and balance.
 * 2. Bank: Manages multiple accounts and provides methods to create a new account and find an account by account number.
 *
 * The main function provides a simple menu interface for the user to interact with the system, allowing them to:
 * - Create an account
 * - Deposit money into an account
 * - Withdraw money from an account
 * - Exit the program
 *
 * Author: Shahil Khan
 * Date: 2025-04-25
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

// Account class to represent a bank account
class Account {
private:
    string accountNumber; // Account number
    string accountHolder; // Account holder's name
    double balance;       // Account balance

public:
    // Constructor to initialize an account
    Account(string accNumber, string accHolder, double initialBalance)
        : accountNumber(accNumber), accountHolder(accHolder), balance(initialBalance) {}

    // Getter for account number
    string getAccountNumber() const {
        return accountNumber;
    }

    // Getter for account holder's name
    string getAccountHolder() const {
        return accountHolder;
    }

    // Getter for account balance
    double getBalance() const {
        return balance;
    }

    // Method to deposit an amount into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Method to withdraw an amount from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
};

// Bank class to manage multiple accounts
class Bank {
private:
    vector<Account> accounts; // Vector to store accounts

public:
    // Method to create a new account
    void createAccount(const string& accountNumber, const string& accountHolder, double initialBalance) {
        Account newAccount(accountNumber, accountHolder, initialBalance);
        accounts.push_back(newAccount);
        cout << "Account created successfully!" << endl;
    }

    // Method to find an account by account number
    Account* findAccount(const string& accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr; // Return nullptr if account not found
    }
};

// Main function to handle user input and interact with the banking system
int main() {
    Bank bank;
    int choice;
    string accountNumber, accountHolder;
    double initialBalance, amount;

    while (true) {
        // Display menu
        cout << "\nBanking System Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Validate input choice
        if(cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(INT_MAX, '\n'); // Ignore invalid input
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            // Create a new account
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter account holder name: ";
            cin >> accountHolder;
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            if(cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(INT_MAX, '\n'); // Ignore invalid input
                cout << "Invalid initial balance. Please try again." << endl;
            } else {
                bank.createAccount(accountNumber, accountHolder, initialBalance);
            }
            break;

        case 2:
            // Deposit money into an account
            cout << "Enter account number: ";
            cin >> accountNumber;
            {
                Account* account = bank.findAccount(accountNumber);
                if (account) {
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    if(cin.fail()) {
                        cin.clear(); // Clear the error flag
                        cin.ignore(INT_MAX, '\n'); // Ignore invalid input
                        cout << "Invalid deposit amount. Please try again." << endl;
                    } else {
                        account->deposit(amount);
                    }
                } else {
                    cout << "Account not found." << endl;
                }
            }
            break;

        case 3:
            // Withdraw money from an account
            cout << "Enter account number: ";
            cin >> accountNumber;
            {
                Account* account = bank.findAccount(accountNumber);
                if (account) {
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    if(cin.fail()) {
                        cin.clear(); // Clear the error flag
                        cin.ignore(INT_MAX, '\n'); // Ignore invalid input
                        cout << "Invalid withdrawal amount. Please try again." << endl;
                    } else {
                        account->withdraw(amount);
                    }
                } else {
                    cout << "Account not found." << endl;
                }
            }
            break;

        case 4:
            // Exit the program
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
