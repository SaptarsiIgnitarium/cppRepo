#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
 
 
int evalRPN(vector<string>& tokens) 
{
    int res=0;
    stack<int> stk;
    for(auto& t : tokens)
    {
        if(t!="+"&&t!="-"&&t!="*"&&t!="/")
        {
            cout<<"Pushing in"<<t<<endl;
            stk.push(stoi(t));
            continue;
//            stk.push(stoi(t));
        }
        else
        {
            if (stk.size() < 2)
            {
                cout << "Error: Not enough operands for operator " << t << endl;
                return 0; // Or handle the error appropriately
            }
            
            int x=stk.top();
            stk.pop();
//           int y=stk.top();
            stk.pop();
            cout<<endl<<t[0];
/*            switch(t[0])
            {
                default:
                    cout<<"Inside Switch";
            }    */
        }
    }
    return res;
}
int main()
{
    //Expression is ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 ==  22
    vector<string> exp = { "10", "6", "9",  "3", "+", "-11", "*", "/",  "*", "17", "+", "5", "+" };
    int res = evalRPN(exp);
    cout<<endl<<"Result of the expression is "<<res;

    cout<<endl;
    return 0;
}