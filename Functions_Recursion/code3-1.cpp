#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee_Details
{
private:
    string Employee_name;
    double Employee_basicsalary;
    double Employee_bonusAmount;

public:
    Employee_Details(string emp_Name, double basic_salary, double emp_Bonus = 2000.0)
    {
        Employee_name = emp_Name;
        Employee_basicsalary = basic_salary;
        Employee_bonusAmount = emp_Bonus;
    }

    inline double Calculate_salary() const // inline function to calculate salary
    {
        return Employee_basicsalary + Employee_bonusAmount;
    }

    void Display_empdetails() const
    {
        cout << "NAME OF EMPLOYEE:" << Employee_name << endl;
        cout << "BASIC SALARY OF EMPLOYEE:" << Employee_basicsalary << endl;
        cout << "BONUS OF EMPLOYEE:" << Employee_bonusAmount << endl;
        cout << "TOTAL SALARY OF EMPLOYEE:" << Calculate_salary() << endl;
        cout << "*******************\n";
    }
};

int main()
{
    vector<Employee_Details> employees; // or we can do by push_back but here copies of objects is not created so more efficient
    employees.emplace_back("Disu", 5000);
    employees.emplace_back("Diya", 6000, 1500);
    employees.emplace_back("Rutvi", 5500);
    employees.emplace_back("Pushti", 2000, 21000);

    cout << "Employee Salary details_" << endl;
    cout << "***************\n";

    for (const auto &emp : employees)
    {
        emp.Display_empdetails();
    }

    cout << "\n24ce062_Disu Makadiya";
    return 0;
}