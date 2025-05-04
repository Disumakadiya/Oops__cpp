#include <iostream>
#include <vector>
using namespace std;

class Calculator
{
private:
    vector<float> results; 

public:
    int add(int a, int b) //overloaded add functions
    {
        int result = a + b;
        results.push_back(result);
        return result;
    }

    float add(float a, float b)
    {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    float add(int a, float b)
    {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    float add(float a, int b)
    {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    // Display stored results
    void displayResults()
    {
        cout << "\nStored Results:" << endl;
        for (int i = 0; i < results.size(); ++i) 
        {
            cout << "Result " << i + 1 << ": " << results[i] << endl;
        }
    }
};

int main() 
{
    Calculator calc;

    // Testing overloaded add functions
    cout << "Addition (int, int): " << calc.add(5, 3) << endl;
    cout << "Addition (float, float): " << calc.add(2.5f, 3.7f) << endl;
    cout << "Addition (int, float): " << calc.add(4, 2.2f) << endl;
    cout << "Addition (float, int): " << calc.add(3.5f, 2) << endl;

    // Display all stored results
    calc.displayResults();
}
