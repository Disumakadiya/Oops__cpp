#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
private:
    string Account_Holder;
    string Account_Number;
    double balance;

public:
    BankAccount(string holder, string number, double initialBalance = 0.0)
    {
        Account_Holder = holder;
        Account_Number = number;
        balance = initialBalance;
    }

    void deposit(double Amount) // to deposit amount in bank
    {
        if (Amount <= 0)
        {
            cout << "Deposited amount is showing positive balance.\n";
        }
        else
        {
            balance += Amount;
            cout << "Deposited " << Amount << " into Account " << Account_Number << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Withdrawal amount must be positive.\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds in account " << Account_Number
                 << ". Available balance: rupees " << balance << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << Account_Number << endl;
        }
    }

    void
    displaySummary() const
    {
        cout << "\n--- Account Summary ---" << endl;
        cout << "Account Holder: " << Account_Holder << endl;
        cout << "Account Number: " << Account_Number << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount acc1("Disu Makadiya ", "001");
    BankAccount acc2("Pushti kansara", "002", 500.00);

    acc1.deposit(150.00);
    acc2.withdraw(100.00);
    acc2.withdraw(1000.00);

    // Display summaries
    acc1.displaySummary();
    acc2.displaySummary();

    cout << "************";
    cout << "24CE062_DISU MAKADIYA";

    return 0;
}
