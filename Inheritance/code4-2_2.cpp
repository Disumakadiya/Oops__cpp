#include <iostream>
#include <string>
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
    const int size = 2;
    Manager managers[size] =
        {
            Manager("DISU", 34, 201, "IT CONSULTANT"),
            Manager("RUTVI", 35, 202, "HR")};

    int search_id;
    cout << "Enter employee ID to search: ";
    cin >> search_id;

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (managers[i].get_employeeid() == search_id)
        {
            cout << "Manager Found:\n";
            managers[i].display_manager();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Manager with Employee ID " << search_id << " not found." << endl;
    }
    cout << "DISU_MAKADIYA 24CE062";
    return 0;
}
