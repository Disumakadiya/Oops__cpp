#include <iostream>
#include <vector>
using namespace std;

class Inventory_Item
{
private:
    int id;
    string name;
    double unitPrice;
    int stock;

public:
    Inventory_Item() // Default constructor
    {
        id = 0;
        name = "Not Mentioned";
        unitPrice = 0.0; // per item prize given
        stock = 0;
    }

    Inventory_Item(int itemId, string itemName, double price, int quantity) // Constructor with item details
    {
        id = itemId;
        name = itemName;
        unitPrice = price;
        stock = quantity;
    }

    void add_Items(int quantity)
    // add new items
    {
        if (quantity > 0)
        {
            stock += quantity;
            cout << quantity << " units added to " << name << ".\n";
        }
        else // displays empty if less than zero
        {
            cout << "Cannot add non-positive quantity.\n";
        }
    }

    void sell_Item(int quantity)
    // Sell items from inventory store
    {
        if (quantity <= 0) // item not in store
        {
            cout << "Invalid quantity to sell.\n";
        }
        else if (quantity > stock) // item not in stock
        {
            cout << "Not enough stock to sell " << quantity << " units of " << name << ".\n";
        }
        else // items sold as excepted
        {
            stock -= quantity;
            cout << quantity << " units of " << name << " sold successfully.\n";
        }
    }

    void show_Details() const // items are deciede
    {
        cout << "\n--- Item Information ---\n";
        cout << "ID:        " << id << endl;
        cout << "Name:      " << name << endl;
        cout << "Price:     " << unitPrice << endl;
        cout << "In Stock:  " << stock << " units\n";
    }
};

int main()
{

    Inventory_Item item1; // Default item
    Inventory_Item item2(101, "Laptop", 799.99, 10);
    Inventory_Item item3(102, "Keyboard", 29.99, 50);

    // Store all items in a vector
    vector<Inventory_Item> inventory = {item1, item2, item3};

    // Update the first item (Mouse)
    inventory[0] = Inventory_Item(100, "Mouse", 19.99, 20);

    // Simulate some stock updates and sales
    inventory[0].add_Items(10); // Add more stock to Mouse
    inventory[1].sell_Item(3);  // Sell 3 Laptops
    inventory[2].sell_Item(60); // Try to sell more Keyboards than available (edge case)

    // Display all item summaries
    for (const Inventory_Item &item : inventory)
    {
        item.show_Details();
    }

    cout << "******************" << endl;
    cout << "\n24CE062_DISU MAKADIYA" << endl;

    return 0;
}
