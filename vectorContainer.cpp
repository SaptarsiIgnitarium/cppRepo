#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<int> testVector = {5,10,20};

    cout << "Size :" <<testVector.size() << endl;

    cout << "At :" << testVector.at(2) << endl;
    cout << "[]" << testVector[1] << endl;

    testVector.push_back(40);
    testVector.push_back(80);

    //iterator
    for (vector<int>::iterator i = testVector.begin(); i != testVector.end(); i++)
    {
        cout << *i << " "; 
    }
    cout << endl;

    testVector.pop_back();

    vector<int>::iterator i = testVector.begin();
    testVector.insert(i,0);

    cout << "Capacity" << testVector.capacity() << endl;

    return 0;
}