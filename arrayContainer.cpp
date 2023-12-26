#include <iostream>
#include <array>
using namespace std;

int main()
{
    //array declaration and initialisation
    std::array<int, 3> testArray = { 5,10,20};

    //methods
    cout << "At" << testArray.at(2) << endl;

    cout << "[]" << testArray[1] << endl;

    cout << "front()" << testArray.front() << endl;

    cout << "back()" << testArray.back() << endl;

    testArray.empty();

    cout << "size()" << testArray.size() << endl;

    return 0;
}