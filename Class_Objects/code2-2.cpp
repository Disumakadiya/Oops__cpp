#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNumber;
    string name;
    int marks[3];

public:
    Student() // Default constructor
    {
        rollNumber = 0;
        name = "N/A";
        marks[0] = marks[1] = marks[2] = 0;
    }

    Student(int rollNumber, string name, int marks[]) // Parameterized constructor
    {
        this->rollNumber = rollNumber;
        this->name = name;
        for (int i = 0; i < 3; i++)
        {
            this->marks[i] = marks[i];
        }
    }

    void display_Details()
    {
        cout << "Roll Number of student is : " << rollNumber << endl;
        cout << "Name of student: " << name << endl;
        cout << "Marks of student: ";
        for (int i = 0; i < 3; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    float calculate_Average()
    {
        int total_marks = 0;
        for (int i = 0; i < 3; i++)
        {
            total_marks += marks[i];
        }
        return total_marks / 3.0f;
    }
};

int main()
{
    int number_Students;
    cout << "Enter the number of students: ";
    cin >> number_Students;

    Student students[number_Students]; // Array of Student objects

    for (int i = 0; i < number_Students; i++)
    {
        int rollNumber;
        string Name;
        int marks[3];

        cout << endl;
        cout << "Enter details of  student " << i + 1 << ":\n";
        cout << "Enter rollnumber: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter name of student : ";
        getline(cin, Name);
        cout << "Enter marks  of students for 3 subjects: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cin >> marks[j];
        }
        students[i] = Student(rollNumber, Name, marks);
    }

    // Display details
    for (int i = 0; i < number_Students; i++)
    {
        cout << "\nStudent " << i + 1 << " Details:\n";
        students[i].display_Details();
        cout << "Average Marks of students: " << students[i].calculate_Average() << endl;
        cout << "*****************************\n";
    }
    cout << "DISU MAKADIYA" << "\n"
         << "24ce062" << endl;
    return 0;
}
