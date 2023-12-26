#include <iostream>
using namespace std;

class shape
{
protected:
    int width,height;

public:
    void setaData(int x, int y)
    {
        width = x;
        height = y;
    }
};

class triangle : public shape
{
public:
    void area()
    {
        cout << "The area of triangle is : " <<(0.5)*width*height <<endl;
    }
};

class rectangle : public shape
{
public:
    void area()
    {
        cout << "The area of the rectangle is :"<<width*height<<endl;
    }
};


int main()
{
    triangle t1;
    rectangle r1;

    t1.setaData(5,10);
    r1.setaData(10,20);

    t1.area();
    r1.area();

    return 0;
}