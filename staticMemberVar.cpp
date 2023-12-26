#include <iostream>
using namespace std;

class Alpha
{
private:
    int a;
    int b;
public:
    Alpha()
    {
        a = 5;
        b = 5;
        //stat++;
    }

    void getData()
    {
        cout << "The value of a is : " << a << endl;
    }
    inline static int stat = 0;

    static int getStat(Alpha ob)
    {
        stat++;
        ob.a++;
        return stat;
    }
};

//int Alpha::stat = 0;


int main()
{
    Alpha a1;
    //cout << "Value using a1 obj = " << a1.stat << endl;
    cout << "Value using a1 obj = " << a1.getStat(a1) << endl;

    Alpha a2;
    cout << "Value using a2 obj = " << a2.stat << endl;
    //cout << "Value using class name = " << Alpha::getStat() << endl;

    a1.getData();
    //Alpha::getData();

    return 0;
}