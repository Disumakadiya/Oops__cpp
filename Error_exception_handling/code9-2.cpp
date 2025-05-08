#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Transaction Log Entry structure
struct Transaction 
{
    string type;  // "Deposit" or "Withdrawal"
    double amount;
    double balanceAfter;
    string description;
};

// BankAccount class definition
class BankAccount
 {
private:
    string accountHolder;
    double balance;
    vector<Transaction> transactionHistory;

    // Log error to a file
    void logError(const string& error) 
    {
        ofstream logFile("error_log.txt", ios::app);
        if (logFile.is_open()) {
            logFile << "Error: " << error << endl;
        }
        logFile.close();
    }

public:
    // Constructor to initialize the account
    BankAccount(const string& holder, double initialBalance) : accountHolder(holder), balance(initialBalance) {}

    // Deposit function
    void deposit(double amount) 
    {
        if (amount <= 0)
        {
            string error = "Attempted to deposit non-positive amount: " + to_string(amount);
            logError(error);
            cout << "Error: Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        Transaction transaction = {"Deposit", amount, balance, "Deposit of " + to_string(amount)};
        transactionHistory.push_back(transaction);
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    // Withdraw function
    void withdraw(double amount)
     {
        if (amount <= 0) {
            string error = "Attempted to withdraw non-positive amount: " + to_string(amount);
            logError(error);
            cout << "Error: Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance)
         {
            string error = "Attempted to withdraw more than available balance: " + to_string(amount);
            logError(error);
            cout << "Error: Insufficient funds. Current balance: " << balance << endl;
            return;
        }
        balance -= amount;
        Transaction transaction = {"Withdrawal", amount, balance, "Withdrawal of " + to_string(amount)};
        transactionHistory.push_back(transaction);
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }

    // Display transaction history
    void showTransactionHistory() const 
    {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (const auto& txn : transactionHistory)
         {
            cout << txn.type << ": " << txn.amount
                 << " | New Balance: " << txn.balanceAfter
                 << " | Description: " << txn.description << endl;
        }
    }

    // Get the current balance
    double getBalance() const
    {
        return balance;
    }
};

int main()
 {
    string holderName;
    double initialBalance;

    // Initializing the bank account
    cout << "Enter account holder name: ";
    getline(cin, holderName);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(holderName, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View Transaction History\n";
        cout << "4. View Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.showTransactionHistory();
                break;
            case 4:
                cout << "Current Balance: " << account.getBalance() << endl;
                break;
            case 5:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
