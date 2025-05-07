#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

// Struct to hold student data
struct Student
 {
    char name[50];
    int marks;
    char grade;
};

// User-defined manipulator for formatting
ostream& tabular(ostream& out)
 {
    out << left << setw(15);
    return out;
}

// Approach 1: Process directly from file
void StreamBasedReport(const char* filename) 
{
    cout << "\n=== Stream-Based Report (Direct Read) ===\n";
    ifstream infile(filename);

    if (!infile) {
        cerr << "Error: Unable to open file.\n";
        return;
    }

    char name[50];
    int marks;
    char grade;

    cout << left << setw(15) << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << endl;
    cout << "-----------------------------------\n";

    while (infile >> name >> marks >> grade) 
    {
        cout << tabular << name << setw(10) << marks << setw(10) << grade << endl;
    }

    infile.close();
}

// Approach 2: Store in array, then display (allows sorting/filtering)
void DynamicReport(const char* filename)
 {
    cout << "\n=== Dynamic Report (Storing in Memory) ===\n";
    ifstream infile(filename);

    if (!infile) 
    {
        cerr << "Error: Unable to open file.\n";
        return;
    }

    const int MAX = 100;
    Student students[MAX];
    int count = 0;

    while (infile >> students[count].name >> students[count].marks >> students[count].grade)
     {
        count++;
    }
    infile.close();

    // Optional: Sort by marks descending
    for (int i = 0; i < count - 1; ++i) 
    {
        for (int j = i + 1; j < count; ++j) 
        {
            if (students[j].marks > students[i].marks) 
            {
                swap(students[i], students[j]);
            }
        }
    }

    cout << left << setw(15) << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << endl;
    cout << "-----------------------------------\n";
    for (int i = 0; i < count; ++i) 
    {
        cout << tabular << students[i].name << setw(10) << students[i].marks << setw(10) << students[i].grade << endl;
    }
}

int main()
 {
    const char* filename = "students.txt";

    StreamBasedReport(filename);
    DynamicReport(filename);

    return 0;
}
