#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string country;

public:
    void setData(string name_a, int age_a, string country_a)
    {
        name = name_a;
        age = age_a;
        country = country_a;
    }

    void getData()
    {
        cout << "Name : "<< name << endl;
        cout << "Age : "<< age << endl;
        cout << "Country : "<< country << endl;
    }
};

int main()
{
    Person p1;
    p1.setData("Saptarsi",23,"India");
    p1.getData();

    return 0;
}