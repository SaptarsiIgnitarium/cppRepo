#include <iostream>
using namespace std;

class Circle
{
private:
    float radius;
public:
    Circle(float rad)
    {
        radius = rad;
    }

    float area()
    {
        float a = radius*radius* 3.14;
        return a; 
    }

    float circumference()
    {
        float c = 2*3.14*radius;
        return c;
    }
};

int main()
{
    Circle obj1(5.0);
    float circle_area = obj1.area();

    cout << "The area of the circle is :" << circle_area;

    float circle_circum = obj1.circumference();
    cout << "The circumference is :" << circle_circum;

    return 0;
}