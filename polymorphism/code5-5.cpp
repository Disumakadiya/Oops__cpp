#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class
class Shape 
{
public:
    virtual double Area() const = 0; // Pure virtual function
    virtual ~Shape() {}              // Virtual destructor
};

// Derived class: Rectangle
class Rectangle : public Shape
 {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override 
    {
        return length * width;
    }
};

// Derived class: Circle
class Circle : public Shape
{
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override
     {
        return M_PI * radius * radius;
    }
};


void StaticShapeCollection() 
{
    cout << "=== Static Collection ===" << endl;

    const int MAX_SHAPES = 3;
    Shape* shapes[MAX_SHAPES];

    // Add shapes manually
    shapes[0] = new Rectangle(10, 5);  
    shapes[1] = new Circle(3);         
    shapes[2] = new Rectangle(6, 2);   

    // Display  and delete
    for (int i = 0; i < MAX_SHAPES; ++i)
     {
        cout << "Shape " << i + 1 << " Area = " << shapes[i]->Area() << endl;
        delete shapes[i]; // Free memory
    }
}

void DynamicShapeCollection() 
{
    cout << "\n=== Dynamic Collection ===" << endl;

    vector<Shape*> shapes;

    // Add shapes dynamically
    shapes.push_back(new Circle(4));        
    shapes.push_back(new Rectangle(7, 3));  
    shapes.push_back(new Circle(2.5));      

    // Display and delete
    for (size_t i = 0; i < shapes.size(); ++i)
     {
        cout << "Shape " << i + 1 << " Area = " << shapes[i]->Area() << endl;
        delete shapes[i]; // Free memory
    }
}

int main() {
    StaticShapeCollection();    // Run static example
    DynamicShapeCollection();   // Run dynamic example
    return 0;
}
