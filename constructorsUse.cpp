#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int rollNo;
    float marks;

public:
    student()
    {
        name = "Null";
        rollNo = 0;
        marks = 0.0;
    }

    student(string name_a,int rollNo_a,float marks_a)
    {
        name = name_a;
        rollNo = rollNo_a;
        marks = marks_a;
    }

    student(student &obj)
    {
        name = obj.name;
        rollNo = obj.rollNo;
        marks = obj.marks;
    }

    void getData()
    {
        cout << "The name of the Student is : "<< name << endl;
        cout << "Their roll no is : " << rollNo << endl;
        cout << "They obtained : "<< marks << "Marks" << endl;
    }
};


int main()
{
    student obj1,obj2("Saptarsi",25,50),obj3(obj2);

    obj1.getData();
    obj2.getData();
    obj3.getData();

    return 0;
}