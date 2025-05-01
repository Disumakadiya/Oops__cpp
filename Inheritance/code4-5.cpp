#include <iostream>
#include <vector>
#include <string>
using namespace std;

class student
{
protected:
    string name;
    int marks;

public:
    student(string n, int m) : name(n), marks(m) {}

    virtual string compute_grade() = 0; // pure virtual func.for grade calculation

    void display_details()
    {
        cout << "Name of student::" << name<<";"<<endl
             << "Marks of student::" << marks<<";"<<endl
             << ",Grade::" << compute_grade() << endl;
    }
};

class Under_graduate : public student
{
public:
    Under_graduate(string n, int m) : student(n, m) {}

    string compute_grade() override
    {
        if (marks >= 90)
            return "A";
        else if (marks >= 80)
            return "B";
        else if (marks >= 70)
            return "C";
        else
            return "F";
    }
};

class Post_graduate : public student
{
public:
    Post_graduate(string n, int m) : student(n, m) {}

    string compute_grade() override
    {
        if (marks >= 90)
            return "A";
        else if (marks >= 70)
            return "B";
        else if (marks >= 60)
            return "C";
        else
            return "F";
    }
};

int main()
{
    vector<student *> students; // pointer to base class to store objects of its derived class
    int n;
    cout << "Enter the number of students::";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "***Enter the details of students" << i + 1 << "***" << endl;
        cout << "ENTER TYPE (1 FOR UNDERGRADUATE,2 FOR POSTGRADUATE)--";
        int type; // 1 or 2
        cin >> type;

        cin.ignore();
        string name;
        cout << "ENTER THE NAME :";
        getline(cin, name);

        int marks_of_students;
        cout <<"ENTER MARKS::";
        cin>>marks_of_students;

        if(type==1)
        {
            students.push_back(new Under_graduate(name,marks_of_students));
        }
        else if(type==2)
        {
            students.push_back(new Post_graduate(name,marks_of_students));
        }
        else
        {
            cout<<"invalid type!!"<<endl;
        }
    }
    
   cout<<"****STUDENT RECORDS******"<<endl;
   for(student* s:students)
   {
    s ->display_details();
   }

   for(student* s:students)
   {
    delete s;//free memory
   }

   return 0;
}