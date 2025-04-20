#include <iostream>
#include <string>
#include <map>
using namespace std;

// Base class
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a)
    {
    }

    void display_person() const
    {
        cout << "Name of person: " << name << endl;
        cout << "Age of that person: " << age << endl;
    }
};

// Intermediate class
class Employee : public Person
{
protected:
    int employee_id;

public:
    Employee(string n = "", int a = 0, int id = 0) : Person(n, a), employee_id(id)
    {
    }

    void display_employee() const
    {
        display_person();
        cout << "Enter the generated Employee ID: " << employee_id << endl;
    }

    int get_employeeid() const
    {
        return employee_id;
    }
};

// Derived class
class Manager : public Employee
{
private:
    string department;

public:
    Manager(string n = "", int a = 0, int id = 0, string dept = "")
        : Employee(n, a, id), department(dept)
    {
    }

    void display_manager() const
    {
        display_employee();
        cout << "Department of Manager: " << department << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    map<int, Manager> manager_details;

    manager_details[111] = Manager("DISU", 18, 111, "CEO");
    manager_details[112] = Manager("SHREYA", 17, 112, "PROJECT MANAGER");
    manager_details[113] = Manager("PUSHTI", 18, 113, "HR");

    int searchemployee_id;
    cout << "Enter Employee ID to search: ";
    cin >> searchemployee_id;

    if (manager_details.find(searchemployee_id) != manager_details.end())
    {
        cout << "\n--- Manager Found ---\n";
        manager_details[searchemployee_id].display_manager();
    }
    else
    {
        cout << "\nManager with Employee ID " << searchemployee_id << " not found.\n";
    }
    cout << "DISU MAKADIYA_24CE062";

    return 0;
}
