#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& number) const//passing by reference to avoid copying
    {
        return Complex(real + number.real, imag + number.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& number) const
    {
        return Complex(real - number.real, imag - number.imag);
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& out, const Complex& c/*number to print on right hand side*/) //<<-belongs to ostream ,not Complex--so friend functiom
    {//complex object print using cout
        out << c.real << (c.imag >= 0 ? " + " : " - ")/*sign handled*/ << abs(c.imag) << "i";
        return out;//cout << c1 << " and " << c2--allows chaining
    }

    // Overload >> operator for input
    friend istream& operator>>(istream& in, Complex& c) 
    {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

int main()
{
    Complex c1, c2;

    // Input complex numbers
    cout << "Input first complex number:\n";
    cin >> c1;

    cout << "\nInput second complex number:\n";
    cin >> c2;

    // Perform addition and subtraction
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    // Output results
    cout << "\nSum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    // Batch operation with vector
    int n;
    cout << "\nEnter number of complex numbers for batch operation: ";
    cin >> n;

    vector<Complex> complex_List(n);//default initialize using constructor
    cout << "\nEnter " << n << " complex numbers:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Complex number " << i + 1 << ":\n";
        cin >> complex_List[i];
    }
    Complex batchSum;
    for (const auto& num : complex_List)//adding all complex numbers
    {
        batchSum = batchSum + num;
    }

    cout << "\nBatch Sum of all complex numbers: " << batchSum << endl;

    return 0;
}
