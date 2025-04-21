#include <iostream>
using namespace std;

class complex
{
private:
    float real, imaginary;

public:
    complex(float r = 0, float i = 0) // default constructor
    {
        real = r;
        imaginary = i;
    }

    complex operator+(const complex &number) const
    {
        return complex(real + number.real, imaginary + number.imaginary);
    }
    complex operator-(const complex &number) const
    {
        return complex(real - number.real, imaginary - number.imaginary);
    }

    void display_sum() const
    {
        cout << real << "+" << imaginary << "i" << endl;
    }

    void display_diff() const
    {
        cout << real << "+" << imaginary << "i" << endl;
    }
};

int main()
{
    complex operator_1(2.4, 3.4);
    complex operator_2(5.6, 7.6);

    complex sum = operator_1 + operator_2;
    complex diff = operator_1 - operator_2;

    cout << "sum is ::";
    sum.display_sum();
    cout << "diff is ::";
    diff.display_diff();

    return 0;
}