#include <iostream>
#include <fstream>
#include <string>

using namespace std;//without stl

void additem()
{
    ofstream file("Inventory.txt", ios::app);
    if (!file)
    {
        cerr << "File not found!" << endl;
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;

    file << name << " " << quantity << " " << price << endl;
    file.close();
    cout << "Item added." << endl;
}

void viewitem()
{
    ifstream file("inventory.txt");
    if (!file)
    {
        cerr << "File not found!" << endl;
        return;
    }

    cout << "Inventory items:" << endl;
    string name;
    int quantity;
    double price;

    while (file >> name >> quantity >> price)
    {
        cout << "Name: " << name << " | Quantity: " << quantity << " | Price: " << price << endl;
    }

    file.close();
}

void searchitem()
{
    ifstream file("inventory.txt");
    if (!file)
    {
        cerr << "File not found!" << endl;
        return;
    }

    string search_name;
    cout << "Enter item name to search: ";
    cin >> search_name;

    string name;
    int quantity;
    double price;
    bool found = false;

    while (file >> name >> quantity >> price)
    {
        if (name == search_name)
        {
            cout << "Item found!" << endl;
            cout << "Name: " << name << " | Quantity: " << quantity << " | Price: " << price << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Item not found." << endl;
    }

    file.close();
}

int main()
{
    int choice;
    do
    {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            additem();
            break;
        case 2:
            viewitem();
            break;
        case 3:
            searchitem();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
//when array is there we need to write size in getline
//char array cin=getline(name of array,size of array)
//getline(cin,name of string)
//char array--strlen() use karvn char.count karva mate
//stringstream==automatically count the words including space only this delimiter line  ne read karva mate 
