#include <iostream>
using namespace std;

int main()
{
    char character;
    cout << "Enter the input character : ";
    cin >> character;

    if (character >= 'a' && character<= 'z')
    {
        cout << "The entered character is lower case"; 
    }
    else if (character >= 'A' && character<= 'Z')
    {
        cout << "The entered character is Upper case";
    }
    else 
        cout << "The entered character is Not a letter"; 
    
    return 0;
}
