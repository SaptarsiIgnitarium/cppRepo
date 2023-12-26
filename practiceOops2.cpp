#include <iostream>
using namespace std;

class mother
{
public:
    void display()
    {
        cout << "This is the mother class" << endl;
    }
};

class daughter: public mother
{
public:
    void display()
    {
        cout << "This is the daughter class" << endl;
    }
};


int main()
{
    daughter d1;
    d1.display();

    return 0;
}