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
    // Default constructor
    Student()
    {
        rollNumber = 0;
        name = "N/A";
        marks[0] = marks[1] = marks[2] = 0;
    }

    // Parameterized constructor
    Student(int rollNumber, string name, int marks[])
    {
        this->rollNumber = rollNumber;
        this->name = name;
        for (int i = 0; i < 3; i++)
        {
            this->marks[i] = marks[i];
        }
    }

    // Function to display student details
    void displayDetails()
    {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 3; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    // Function to calculate the average marks
    float calculateAverage()
    {
        int total = 0;
        for (int i = 0; i < 3; i++)
        {
            total += marks[i];
        }
        return total / 3.0f;
    }
};

int main()
{
    int numStudents;

    // Taking input for number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Create an array of Student objects
    Student students[numStudents]; // Array of Student objects

    // Loop to take input for each student
    for (int i = 0; i < numStudents; i++)
    {
        int rollNumber;
        string name;
        int marks[3];

        // Input for student details
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter marks for 3 subjects: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cin >> marks[j];
        }

        // Create a Student object using parameterized constructor
        students[i] = Student(rollNumber, name, marks);
    }

    // Display details and calculate average for each student
    for (int i = 0; i < numStudents; i++)
    {
        cout << "\nStudent " << i + 1 << " Details:\n";
        students[i].displayDetails();
        cout << "Average Marks: " << students[i].calculateAverage() << endl;
        cout << "-----------------------------\n";
    }
    cout << "DISU MAKADIYA" << "\n"
         << "24ce062" << endl;
    return 0;
}
