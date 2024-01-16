#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack
{
private:
    stack<int> mainStack;     //to store the main stack
    stack<int> minStack;      //to store the minimum value

public:
    MinStack()
    {
          //constructor   
    }

    void push(int val)
    {
        mainStack.push(val);
        if(minStack.empty() || val < minStack.top())    //if value is less than minstacks top push it
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        if(!mainStack.empty())
        {
            if(minStack.top() == mainStack.top())       //if the value we are removing from mainstack is the same as minstacks top
            {                                           //that means it is the current min value and we have to remove it
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top()
    {
        if(!mainStack.empty())
        {
            return mainStack.top();
        }
        else 
            return INT_MIN;
    }

    int getMin()
    {
        if(!minStack.empty())
        {
            return minStack.top();
        }
        else
            return INT_MIN;
    }
};

int main()
{
    MinStack minimumStack;

    minimumStack.push(-1);
    minimumStack.push(0);
    minimumStack.push(-5);

    cout << "Minimum element in the stack is : " << minimumStack.getMin() << endl;

    cout << "Top element in the stack is : "<< minimumStack.top() << endl;


    minimumStack.pop();

    cout << "Top element in the stack is : "<< minimumStack.top() << endl;

    cout << "Minimum elemnet after pop is : " << minimumStack.getMin() << endl;

    return 0;
}