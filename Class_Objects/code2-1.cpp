#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length;
    float width;

public:
    // Member function
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

    // function to calculate the area of the rectangle
    float area_of_rectangle()
    {
        return length * width;
    }

    // function to calculate the perimeter of the rectangle
    float perimeter_of_rectangle()
    {
        return 2 * (length + width);
    }

    void display_Dimensions()
    {
        cout << "Length of rectangle: " << length << ", Width of rectangle: " << width << endl;
    }
};

int main()
{
    Rectangle rectangle_1, rectangle_2;
    rectangle_1.set_Dimensions(15, 20);
    rectangle_2.set_Dimensions(17, 18);

    // display details of both rectangle
    cout << "1: Rectangle length:15,width:20" << endl;
    cout << "area is " << rectangle_1.area_of_rectangle() << endl;
    cout << "perimeter is " << rectangle_1.perimeter_of_rectangle() << endl;
    cout << "***********" << endl;

    cout << "2: Rectangle Length: 17, Width: 18" << endl;
    cout << "Area is" << rectangle_2.area_of_rectangle() << endl;
    cout << "perimeter is " << rectangle_2.perimeter_of_rectangle() << endl;
    cout << endl;

    cout << "***********" << endl;
    cout << "***********" << endl;

    // Updated dimensions of  rectangle
    rectangle_1.update_dimensions(22, 23);
    cout << "updated dimension of rectangle_1";
    rectangle_1.display_Dimensions();
    cout << "Updated Area: " << rectangle_1.area_of_rectangle() << endl;
    cout << "Updated Perimeter: " << rectangle_2.perimeter_of_rectangle() << endl;
    cout << "***********" << endl;

    rectangle_2.update_dimensions(33, 77);
    cout << "updated dimension of rectangle_2 ";
    rectangle_2.display_Dimensions();
    cout << "Updated Area: " << rectangle_2.area_of_rectangle() << endl;
    cout << "Updated Perimeter: " << rectangle_2.perimeter_of_rectangle() << endl;
    cout << "***********" << endl;
    cout << "***********" << endl;

    cout << "DISU MAKADIYA_24CE062";
    return 0;
}
