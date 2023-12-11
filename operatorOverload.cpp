#include <iostream>
using namespace std;

class optr
{
private :
    int var1;
public :
    optr(int x)
    {
        var1 = x;
    }

    void operator--()
    {
        --var1;
    }

    void operator--(int)
    {
        var1--;   
    }
    
    void getData()
    {
        cout << var1;
    }
};

int main()
{
    optr obj(34);

    --obj;
    obj--;

    obj.getData();

    return 0;
}