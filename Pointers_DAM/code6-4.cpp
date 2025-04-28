#include <iostream>
using namespace std;

// with virtual destructor
class Base
{
public:
    Base()
    {
        cout << "Base constructor\n";
    }
    virtual ~Base()
    {
        cout << "Base destructor\n";
    } // Notice: virtual
};

class Derived : public Base
{
private:
    int *data;

public:
    Derived()
    {
        data = new int[100]; // Dynamic allocation
        cout << "Derived constructor\n";
    }
    ~Derived()
    {
        delete[] data; // Clean up
        cout << "Derived destructor\n";
    }
};

int main()
{
    Base *obj = new Derived();
    delete obj; // Correctly calls Derived::~Derived() then Base::~Base()
    return 0;
}

// without virtual destructor
/*class Base
{
public:
    Base()
    {
        cout << "Base constructor\n";
    }
    ~Base()
    {
         cout << "Base destructor\n";
    } // Notice: virtual
};

class Derived : public Base
{
private:
    int* data;
public:
    Derived()
    {
        data = new int[100];  // Dynamic allocation
        cout << "Derived constructor\n";
    }
    ~Derived()
    {
        delete[] data;  // Clean up
        cout << "Derived destructor\n";
    }
};

int main()
{
    Base* obj = new Derived();
    delete obj;  // Correctly calls Derived::~Derived() then Base::~Base()
    return 0;
}
*/
