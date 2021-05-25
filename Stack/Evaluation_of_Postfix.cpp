#include <bits/stdc++.h>
using namespace std;

// In a postfix expression, operands come first, then operators.
// Eg - ab+.
// Now we have to evaluate the value of an arithmetic expression in Reverse Polish Notation (Postfix Expression).
// Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
// It is guaranteed that the given RPN expression is always valid. 
// That means the expression would always evaluate to a result, and there will not be any division by zero operation.
// Example:
//Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
//Output: 22
//Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22

//CODE:

int evalRPN(vector<string>& tokens) 
{
    stack<int> nums;
    for(int i=0; i<tokens.size(); i++)
    {        
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
               int val = stoi(tokens[i]); 
               nums.push(val);
               
            }
            else
            {
                if(nums.size() >= 2)
               {
                   int a = nums.top();
                   nums.pop();
                   int b = nums.top();
                   nums.pop(); 
                   if(tokens[i] == "+")
                    {   
                        int x = a + b;
                        nums.push(x);
                        
                    } 
                    else if(tokens[i] == "-")
                    {
                        int x = b - a;
                        nums.push(x);
                    }   
                    else if(tokens[i] == "*")
                    {
                        int x = a * b;
                        nums.push(x);
                    }   
                    else if(tokens[i] == "/")
                    {
                        int x = b/a;
                        nums.push(x);
                    }   
               }
                
            }
    }
    return nums.top();        
}

int main()
{
    vector<string> tokens;
    int n;          // Size of Vector
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string temp;
        cin>>temp;
        tokens.push_back(temp);
    }
    cout << evalRPN(tokens);
    return 0;

}