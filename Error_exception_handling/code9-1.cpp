#include <iostream>
#include <limits>//for data types range
#include <string>
#include <sstream>

using namespace std;

// Function to safely get a valid double input from the user
double getValidInput(const string& prompt)
 {
    double value;
    string input;

    while (true)
     {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);

        // Try to extract a number
        if (ss >> value && ss.eof())
         {
            return value;
        } else
         {
            cout << "Invalid input. Please enter a numeric value.\n";
        }
    }
}

int main() 
{
    cout << "--- Loan to Income Ratio Calculator ---\n";

    // Get and validate loan amount
    double loanAmount = getValidInput("Enter total loan amount: ");

    double income;
    // Get and validate income, ensuring it's not zero
    while (true)
     {
        income = getValidInput("Enter annual income: ");
        if (income == 0.0)
         {
            cout << "Annual income cannot be zero. Please enter a valid income.\n";
        } 
        else
         {
            break;
        }
    }

    // Calculate and display loan-to-income ratio
    double ratio = loanAmount / income;
    cout << "\nLoan-to-Income Ratio: " << ratio << endl;

    // Optional: Add decision threshold (e.g., > 0.4 is risky)
    if (ratio > 0.4)
     {
        cout << "Note: High loan-to-income ratio. May affect eligibility.\n";
    }
     else
      {
        cout << "Loan-to-income ratio is within acceptable range.\n";
    }

    return 0;
}
