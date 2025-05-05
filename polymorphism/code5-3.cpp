#include <iostream>
#include <stack>
using namespace std;

class Point 
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload unary -
    Point operator-() const
    {
        return Point(-x, -y);
    }

    // Overload +
    Point operator+(const Point& number) const 
    {
        return Point(x + number.x, y + number.y);
    }

    // Overload ==
    bool operator==(const Point& number) const
    {
        return (x == number.x) && (y == number.y);
    }

    void display() const 
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Main function using STL stack
int main()
{
    Point p1(3, 4), p2(1, 2), result;
    stack<Point> history;

    // Initial state
    result = p1;
    history.push(result);
    cout << "Initial: ";
    result.display();

    // Add p2
    result = result + p2;
    history.push(result);
    cout << "After addition: ";
    result.display();

    // Negate
    result = -result;
    history.push(result);
    cout << "After negation: ";
    result.display();

    // Undo last operation
    history.pop();           // Remove current
    result = history.top();  // Get previous
    cout << "After undo: ";
    result.display();

    return 0;
}
