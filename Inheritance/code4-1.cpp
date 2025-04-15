#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape // base class
{
protected:
    double radius;

public:
    Shape(double r = 0.0) : radius(r) // default constructor
    {
    }

    void Set_radius(double r)
    {
        radius = r;
    }

    double get_radius() const // as cannot be changed by all data members
    {
        return radius;
    }
};

class Circle : public Shape
{
public:
    Circle(double r = 0.0) : Shape(r)
    {
    }
    double get_area() const
    {
        return M_PI * radius * radius;
    }
};

// first approach by dynamic handling and flexibility so by <vector>
void dynamic_circle()
{
    int n;
    cout << "enter the number of circles";
    cin >> n;

    vector<Circle> circles;
    for (int i = 0; i < n; ++i)
    {
        double r;
        cout << "Enter the radius for circle " << i + 1 << "::";
        cin >> r;
        circles.emplace_back(r); // creates objects directly inside the vector//circles.push_back(circle(r));
    }

    cout << "Circle Areas:" << endl; // display area of circle
    for (int i = 0; i < n; ++i)
    {
        cout << "Circle" << i + 1 << "area --" << circles[i].get_area() << "sq.units" << endl;
    }
}

// 2nd approach static array of circles
void static_circle()
{
    const int size = 2;
    Circle circles[size];

    cout << "by static declaring the no.of circles--" << size << endl;
    for (int i = 0; i < size; ++i)
    {
        double r;
        cout << "enter the radius of circle" << i + 1 << ":";
        cin >> r;
        circles[i].Set_radius(r);
    }

    cout << "circle area by static approach" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "circle" << i + 1 << "area--" << circles[i].get_area() << "sq.units" << endl;
    }
}

int main()
{
    dynamic_circle();
    static_circle();

    cout << "****************" << endl
         << "24CE062_DISU MAKADIYA";
    return 0;
}