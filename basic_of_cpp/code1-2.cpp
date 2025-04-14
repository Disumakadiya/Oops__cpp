#include <iostream>
#include <string>

using namespace std;

// Maximum number of products that can be added
const int MAX_PRODUCTS = 100;

// Struct to represent a Product
struct Product
{
    int id;
    string name;
    int quantity;
    double price;
};

// Array to store products
Product store[MAX_PRODUCTS];
int productCount = 0; // Track the number of products in the inventory

// Function to add a new product
void addProduct(int id, const string &name, int quantity, double price)
{
    if (productCount < MAX_PRODUCTS)
    {
        store[productCount].id = id;
        store[productCount].name = name;
        store[productCount].quantity = quantity;
        store[productCount].price = price;
        productCount++;
    }
    else
    {
        cout << "store full! Cannot add more products." << endl;
    }
}

// Function to update the quantity of an existing product
void updateQuantity(int id, int quantity)
{
    for (int i = 0; i < productCount; i++)
    {
        if (store[i].id == id)
        {
            store[i].quantity += quantity;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

// Function to calculate the total value of all products
double calculateTotalValue()
{
    double totalValue = 0;
    for (int i = 0; i < productCount; i++)
    {
        totalValue += store[i].quantity * store[i].price;
    }
    return totalValue;
}

// Test the system
int main()
{
    addProduct(1, "Laptop", 10, 1000);
    addProduct(2, "Phone", 5, 500);
    addProduct(3, "charger", 2, 200);
    updateQuantity(1, 5);

    cout << "Total value of inventory in order : " << calculateTotalValue() << endl;
    cout << "24CE062_DISU MAKADIYA" << endl;

    return 0;
}
