#include <iostream>
#include <string>

using namespace std;

// BankAccount class definition
class BankAccount
{
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize the account
    BankAccount(string name, int accNo, double initialBalance)
    {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    // Function to deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $" << amount << " successfully." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully." << endl;
        }
    }

    // Function to check balance
    void checkBalance() const
    {
        cout << "\n--- Account Info ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

// Main function
int main()
{

    BankAccount acc1("Disu Makadiya", 123456, 1000.00);

    acc1.checkBalance();
    acc1.deposit(500);
    acc1.withdraw(200);
    acc1.withdraw(1500);
    acc1.checkBalance();

    cout << "DISU MAKADIYA_24CE062" << endl;
    return 0;
}
