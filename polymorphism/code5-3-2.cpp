#include <iostream>// Custom stack implementation
#define MAX 100
using namespace std;

// Point class with operator overloading
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
    Point operator+(const Point& other) const
    {
        return Point(x + other.x, y + other.y);
    }

    // Overload ==
    bool operator==(const Point& other) const
    {
        return (x == other.x) && (y == other.y);
    }

    void display() const 
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

class PointStack
{
private:
    Point stack[MAX];
    int top;

public:
    PointStack() : top(-1) {}

    bool isEmpty() const 
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == MAX - 1;
    }

    void push(const Point& p)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
        } else
        {
            stack[++top] = p;
        }
    }

    Point pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return Point();
        } else 
        {
            return stack[top--];
        }
    }

    Point peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return Point();
        } 
        else
        {
            return stack[top];
        }
    }
};

int main()
 {
    Point p1(3, 4), p2(1, 2), result;
    PointStack history;

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
    history.pop(); // Remove current
    result = history.peek(); // Get previous
    cout << "After undo: ";
    result.display();

    return 0;
}
