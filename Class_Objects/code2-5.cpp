/*if(i==0)//student1 is called as default constructor
 {
 Student[i]=Student();
 }
 else
 {
 student[i]=Student(roll,m1,m2,m3);//pass by value
 }

 pass by address__constant pointer to its base address
 if array of object is passed then it is pass by address
 */

#include <iostream>
#include <math.h>
#include <string>

using namespace std;
class loan
{
private:
    int loan_Id;
    string applicant_name;
    double loan_amount;
    double interest_Rate; // ANNUAL RATE IS PERCENTAGE
    int loanTerm;

public:
    loan() // default constructor to initialize value to default
    {
        loan_Id = 0;
        applicant_name = "INPUT NOT GIVEN";
        loan_amount = 0.0;
        interest_Rate = 0.0;
        loanTerm = 0;
    }
    loan(int Id, string name, double amount, double Rate, int loan_tenure)
    // parametrized constructor to initialize with user inputs
    {
        loan_Id = Id;
        applicant_name = name;
        loan_amount = amount;
        interest_Rate = Rate;
        loanTerm = loan_tenure;
    }

    // Member function to calculate monthly EMI
    double calculateEMI()
    {
        double p = loan_amount;

        // Convert annual interest rate to monthly rate
        double r = (interest_Rate / 100) / 12;
        // Use the EMI formula
        int t = loanTerm;
        double EMI = p * r * pow(1 + r, t) / (pow(1 + r, t) - 1);
        return EMI;
    }

    // Member function to display loan details
    void displayLoandetails()
    {
        double EMI = calculateEMI();
        cout << "Loan ID: " << loan_Id << endl;
        cout << "Applicant Name: " << applicant_name << endl;
        cout << "Loan Amount: " << loan_amount << endl;
        cout << "Interest Rate: " << interest_Rate << "%" << endl;
        cout << "Loan Term (in months): " << loanTerm << endl;
        cout << "Monthly EMI: " << EMI << endl;
    }
};

int main()
{
    int loan_id;
    string applicantname;
    double loan_amount, interset_Rate;
    int loanTerm;

    cout << "Enter the loan Id:";
    cin >> loan_id;
    cin.ignore();

    cout << "Enter Applicant Name::";
    getline(cin, applicantname);

    cout << "Enter the loan Amount:";
    cin >> loan_amount;

    cout << "Enter the interset Rate:";
    cin >> interset_Rate;

    cout << "Enter the loan Tenure(month):";
    cin >> loanTerm;

    cout << "**********************" << endl;
    // create a loan object for parametrized constructor
    loan Loan(loan_id, applicantname, loan_amount, interset_Rate, loanTerm);

    Loan.displayLoandetails();

    cout << "DISU MAKADIYA_24CE062";
    return 0;
}
