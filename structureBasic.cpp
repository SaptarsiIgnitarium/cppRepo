#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int rollNo;
    int marks;
};

int main()
{
    student s1;
    s1 = {"Arun",23,79};

    cout << "The name of student is : "<< s1.name <<endl;
    cout << "Roll No is : " << s1.rollNo << endl;
    cout << "marks obtained : "<< s1.marks;

    return 0;
}
