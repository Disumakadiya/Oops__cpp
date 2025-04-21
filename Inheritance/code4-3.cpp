#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Fuel_type // base class
{
protected:
    string fuel;

public:
    Fuel_type(string f = "") : fuel(f) {} // default constructor which intialize fuel=f

    void display_fuel() const // same function call for every car
    {
        cout << "FUEL TYPE:" << fuel << endl;
    }
};

class car_brand // base class
{
protected:
    string brand_name;

public:
    car_brand(string b = "") : brand_name(b) {} // dafault constructor

    void display_brand() const
    {
        cout << "Brand name:" << brand_name << endl;
    }
};

class Car : public Fuel_type, public car_brand // derived class
{
private:
    int car_id;

public:
    Car(int id = 0, string f = "", string b = "") : Fuel_type(f), car_brand(b), car_id(id)
    {
    }
    // parameterized constructor to display all details

    void display_car() const
    {
        cout << "CAR ID:" << car_id << endl;
        display_fuel();
        display_brand();
        cout << "**********";
    }

    int get_id() const
    {
        return car_id;
    }
};

int main()
{
    vector<Car> inventory; // to store all car dynamically
    queue<Car> service;    // real world service

    int choice;

    do
    {
        cout << "\n====== Vehicle Management System ======\n";
        cout << "1. Add Car to Inventory\n";
        cout << "2. View All Cars in Inventory\n";
        cout << "3. Add Car to Service Queue\n";
        cout << "4. View Service Queue\n";
        cout << "5. Service (Remove) Car from Queue\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string fuel, brand;
            cout << "Enter Car_ID: ";
            cin >> id;
            cout << "Enter Fuel_type: ";
            cin >> fuel;
            cout << "Enter Brand_Name: ";
            cin >> brand;
            inventory.push_back(Car(id, fuel, brand));
            cout << " Car added to inventory.\n"; // added message
            break;
        }
        case 2:
        {
            cout << "\n All Cars in Inventory:\n";
            if (inventory.empty()) // not available throws error
            {
                cout << "No cars in inventory.\n";
            }
            else
            {
                for (const Car &c : inventory)
                {
                    c.display_car(); // display details
                }
            }
            break;
        }
        case 3:
        {
            int car_id;
            cout << "Enter Car ID to add to service queue: ";
            cin >> car_id;
            bool found = false;
            for (const Car &c : inventory)
            {
                if (c.get_id() == car_id)
                {
                    service.push(c); // if car available then servie msg throws
                    cout << " Car added to service.\n";
                    found = true;
                    break;
                }
            }
            if (!found) // not availbale in service then throws error msg
            {
                cout << "Car ID not found in inventory.\n";
            }
            break;
        }
        case 4:
        {
            cout << "\n Cars in Service (Queue):\n";
            if (service.empty())
            {
                cout << "Service queue is empty.\n";
            }
            else
            {
                queue<Car> temp = service;
                while (!temp.empty())
                {
                    temp.front().display_car(); // add car from first
                    temp.pop();
                }
            }
            break;
        }
        case 5:
        {
            if (!service.empty())
            {
                cout << "\nServicing Car:\n";
                service.front().display_car();
                service.pop(); // remove car by FIFO
            }
            else
            {
                cout << " Service queue is empty.\n";
            }
            break;
        }

        default:
            cout << "invalid choice!! try again";
        }
    } while (choice != 6);

    cout << "DISU MAKADIYA_24CE062";
    return 0;
}