#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Transaction
{
    string type;
    double amount;
};

// Base class
class BankAccount 
{
protected:
    string accountNumber;
    double balance;
    vector<Transaction> transactionHistory;

public:
    BankAccount(string acc_Num, double initial_Balance):accountNumber(acc_Num), balance(initial_Balance) 
    {
        cout << "BankAccount created: " << accountNumber << endl;
    }

    virtual ~BankAccount()//virtual destructor
    {
        cout << "BankAccount destroyed: " << accountNumber << endl;
    }

    virtual void deposit(double amount) //to add amount and total deposit
    {
        balance += amount;
        transactionHistory.push_back({"Deposit", amount});//to add in history transactions
    }

    virtual bool withdraw(double amount)
     {
        if (balance >= amount)
        {
            balance -= amount;
            transactionHistory.push_back({"Withdraw", amount});
            return true;
        }
        cout << "Insufficient balance!" << endl;
        return false;
    }

    void undoLastTransaction()
     {
        if (!transactionHistory.empty()) 
        {
            Transaction last = transactionHistory.back();
            transactionHistory.pop_back();
            if (last.type == "Deposit") balance -= last.amount;
            else if (last.type == "Withdraw") balance += last.amount;
            cout << "Undid last transaction: " << last.type << " of " << last.amount << endl;
        }
         else 
        {
            cout << "No transaction to undo." << endl;
        }
    }

    virtual void display() const 
    {
        cout << "Account: " << accountNumber << ", Balance: " << balance << endl;
    }
};

// SavingsAccount class
class SavingsAccount : public BankAccount 
{
private:
    double interestRate; 

public:
    SavingsAccount(string accNum, double initial_Balance, double rate)
        : BankAccount(accNum, initial_Balance), interestRate(rate) {}

    void applyInterest() 
    {
        double interest = balance * interestRate;
        deposit(interest); // Reuse deposit method
        cout << "Interest applied: " << interest << endl;
    }

    void display() const override
    {
        BankAccount::display();
        cout << "Account Type: Savings, Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

// CurrentAccount class
class CurrentAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, double initial_Balance, double overdraft)
        : BankAccount(accNum, initial_Balance), overdraftLimit(overdraft) {}

    bool withdraw(double amount) override 
    {
        if (balance + overdraftLimit >= amount)
         {
            balance -= amount;
            transactionHistory.push_back({"Withdraw", amount});
            return true;
        }
        cout << "Overdraft limit exceeded!" << endl;
        return false;
    }

    void display() const override
     {
        BankAccount::display();
        cout << "Account Type: Current, Overdraft Limit: " << overdraftLimit << endl;
    }
};

// Example usage
int main() {
    SavingsAccount sa("SA123", 1000.0, 0.05);
    sa.deposit(200);
    sa.withdraw(150);
    sa.applyInterest();
    sa.display();
    sa.undoLastTransaction();
    sa.display();

    cout << "--------------------------" << endl;

    CurrentAccount ca("CA456", 500.0, 300.0);
    ca.deposit(100);
    ca.withdraw(700);
    ca.withdraw(300); // Should fail due to overdraft limit
    ca.display();
    ca.undoLastTransaction();
    ca.display();

    return 0;
}
