#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Struct to hold student data
struct Student 
{
    string name;
    float marks;
    double tuitionFee;
};

// User-defined manipulator for currency formatting
ostream& currency(ostream& out)
 {
    out << "₹";
    return out;
}

int main() 
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();  // Clear newline

    vector<Student> students(n);

    // Input student data
    for (int i = 0; i < n; ++i)
     {
        cout << "\nEnter name of student " << i + 1 << ": ";
        getline(cin, students[i].name);

        cout << "Enter marks of " << students[i].name << ": ";
        cin >> students[i].marks;

        cout << "Enter tuition fee for " << students[i].name << ": ";
        cin >> students[i].tuitionFee;

        cin.ignore();  // Clear newline
    }

    // Output header
    cout << "\n\n" << setfill('=') << setw(50) << "=" << endl;
    cout << setfill(' ') << left << setw(20) << "Student Name"
         << setw(15) << "Marks"
         << setw(15) << "Tuition Fee" << endl;
    cout << setfill('-') << setw(50) << "-" << endl;

    // Display student data
    cout << setfill(' ');
    for (const auto& s : students) 
    {
        cout << left << setw(20) << s.name
             << fixed << setprecision(2) << setw(15) << s.marks
             << currency << fixed << setprecision(2) << s.tuitionFee << endl;
    }

    cout << setfill('=') << setw(50) << "=" << endl;

    return 0;
}
