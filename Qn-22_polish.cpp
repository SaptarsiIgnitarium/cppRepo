#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int polishNotation(vector<string>& tokens)
{
    stack<int> operands;

    for(const auto& token : tokens)
    {
        if(token == "+" || token == "-" || token == "/" || token == "*")
        {
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();

            if(token == "+")
            {
                operands.push(op1+op2);
            }
            else if(token == "-")
            {
                operands.push(op1-op2);
            }
            else if(token == "*")
            {
                operands.push(op1*op2);
            }
            else
            {
                operands.push(op1/op2);
            }
        }
        else
        {
            operands.push(stoi(token));
        }
    }
    return operands.top();
}


int main()
{
    vector<string> tokens = {"2","1","+","3","*"};

    cout << "Result : " << polishNotation(tokens) << endl;

    return 0;
}