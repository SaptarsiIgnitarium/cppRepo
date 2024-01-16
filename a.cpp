#include <iostream>
using namespace std;

class base
{
public:
    
    base()
    {
        cout << "base class Constructor";
    }
    virtual ~base()
    {
        cout << "base class Destructor";
    }
};

class child : public base
{
public:
    
    child()
    {
        cout << "child class Constructor" << endl;
    }
    ~child()
    {
        cout << "child class Destructor" << endl;
    }
};

void max(int, int);

int main()
{
    base* ptr = new child;

    return 0;

    void * (int ,int)
}