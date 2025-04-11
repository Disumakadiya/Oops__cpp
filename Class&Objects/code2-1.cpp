#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length;
    float width;

public:
    // Member function to set the dimensions
    void set_Dimensions(float l, float w)
    {
        length = l;
        width = w;
    }

    void update_dimensions(float l, float w)
    {
        length = l;
        width = w;
    }

    // Member function to calculate and return the area of the rectangle
    float area()
    {
        return length * width;
    }

    // Member function to calculate and return the perimeter of the rectangle
    float perimeter()
    {
        return 2 * (length + width);
    }

    void displayDimensions()
    {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main()
{
    // Create multiple Rectangle objects
    Rectangle rect1, rect2;

    // Initialize dimensions for the first rectangle
    rect1.set_Dimensions(5, 3);

    // Initialize dimensions for the second rectangle
    rect2.set_Dimensions(7, 4);

    // Display area and perimeter of the first rectangle
    cout << "Rectangle 1 - Length: 5, Width: 3" << endl;
    cout << "Area: " << rect1.area() << endl;
    cout << "Perimeter: " << rect1.perimeter() << endl;
    cout << endl;

    // Display area and perimeter of the second rectangle
    cout << "Rectangle 2 - Length: 7, Width: 4" << endl;
    cout << "Area: " << rect2.area() << endl;
    cout << "Perimeter: " << rect2.perimeter() << endl;
    cout << endl;

    // Update the dimensions of the first rectangle
    rect1.update_dimensions(12, 8);
    cout << "Rectangle 1 Updated Dimensions: ";
    rect1.displayDimensions();
    cout << "Area: " << rect1.area() << endl;
    cout << "Perimeter: " << rect1.perimeter() << endl;
    cout << endl;

    // Update the dimensions of the second rectangle
    rect2.update_dimensions(32, 7);
    cout << "Rectangle 2 Updated Dimensions: ";
    rect2.displayDimensions();
    cout << "Area: " << rect2.area() << endl;
    cout << "Perimeter: " << rect2.perimeter() << endl;

    cout<<"Disu Makadiya_24ce062";
    return 0;
}
