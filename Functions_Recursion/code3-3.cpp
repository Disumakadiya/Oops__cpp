#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string holderName;
    double balance;

    static int totalAccounts;

public:
    BankAccount(int accNum, const string &name, double initialBalance)
        : accountNumber(accNum), holderName(name), balance(initialBalance)
    {
        totalAccounts++;
    }

    // Transfer funds to another account using int return instead of bool
    int transferTo(BankAccount &receiver, double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            receiver.balance += amount;
            return 1; // success
        }
        return 0; // failure
    }

    void display() const
    {
        cout << "Account Number: " << accountNumber
             << ", Name: " << holderName
             << ", Balance: $" << balance << endl;
    }

    int getAccountNumber() const { return accountNumber; }
    static int getTotalAccounts() { return totalAccounts; }
};

int BankAccount::totalAccounts = 0;

BankAccount *findAccount(vector<BankAccount> &accounts, int accNum)
{
    for (auto &acc : accounts)
    {
        if (acc.getAccountNumber() == accNum)
            return &acc;
    }
    return nullptr;
}

int main()
{
    vector<BankAccount> accounts;
    int choice;

    do
    {
        cout << "\nBank Account Management System\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Transfer Funds\n";
        cout << "4. Show Total Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int accNum;
            string name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> balance;

            accounts.emplace_back(accNum, name, balance);
            cout << "Account created successfully.\n";
        }
        else if (choice == 2)
        {
            cout << "\nAll Accounts:\n";
            for (const auto &acc : accounts)
                acc.display();
        }
        else if (choice == 3)
        {
            int fromAcc, toAcc;
            double amount;
            cout << "Enter sender account number: ";
            cin >> fromAcc;
            cout << "Enter receiver account number: ";
            cin >> toAcc;
            cout << "Enter amount to transfer: ";
            cin >> amount;

            BankAccount *sender = findAccount(accounts, fromAcc);
            BankAccount *receiver = findAccount(accounts, toAcc);

            if (sender && receiver)
            {
                int result = sender->transferTo(*receiver, amount);
                if (result == 1)
                    cout << "Transfer successful.\n";
                else
                    cout << "Transfer failed. Insufficient balance or invalid amount.\n";
            }
            else
            {
                cout << "Invalid account number(s).\n";
            }
        }
        else if (choice == 4)
        {
            cout << "Total Accounts Created: " << BankAccount::getTotalAccounts() << endl;
        }
        else if (choice == 5)
        {
            cout << "Exiting system. Goodbye!\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    cout << "*****************" << endl;
    cout << "24CE062_Disu Makadiya " << endl;
    return 0;
}
