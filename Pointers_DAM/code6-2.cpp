#include<iostream>
using namespace std;
class Point
{
private:
    int x,y;
public:
    Point(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
    }
    Point* move(int &dx,int &dy)
    {
        x+=dx;
        y+=dy;
        return this;//enable chaining
    }

    void display() const
    {
        cout<<"point("<<x<<","<<y<<")"<<endl;
    }
};

int main()
{
    int dx1, dy1, dx2, dy2;

    Point p(5, 5);
    cout << "Initial: ";
    p.display();

    cout << "Enter first shift (dx1 dy1): ";
    cin >> dx1 >> dy1;

    cout << "Enter second shift (dx2 dy2): ";
    cin >> dx2 >> dy2;

    // Chainable movement
    p.move(dx1, dy1)->move(dx2, dy2);

    cout << "After chained movement: ";
    p.display();

    cout<<"24CE062_DISU MAKADIYA";
    return 0;
}
//6.2----method chaining
//calling more than one time in single line

//passes objects as pointer address
//move(argumentws)
//creates point object
//point* p=new point(x,y);
//apply movements using chaining
//p ->move(dx1,dy1)->move(dx2,dy2);
//display
//p->display();

