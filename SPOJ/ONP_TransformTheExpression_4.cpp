/*
Q. Write a program to convert Infix expression to Postfix expression. Get the Infix expression in string
format.
Algorithm:
1.	Print operands as they arrive.

2.	If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.

3.	If the incoming symbol is a left parenthesis, push it on the stack.

4.	If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.

5.	If the incoming symbol has higher precedence than the top of the stack, push it on the stack.

6.	If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.

7.	If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.

8.	At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)
*/

using namespace std;

#include<bits/stdc++.h>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
#define getmax(a,b) a>b?a:b

void rpn(string str)
{
    stack<char> s;
    int len = str.length();
    FOR(i,0,len)
    {
        if(isalpha(str[i]))
            cout<<str[i];
        else
        {
            if(s.empty() || s.top() == '(' || str[i] == '(')
                s.push(str[i]);
            else if(str[i] == ')')
            {
                while(s.top() != '(')
                {
                    cout<<s.top();
                    s.pop();
                }
                //if(!s.empty())
                    s.pop(); // To remove the bracket
            }
            else if( (str[i] == '^' && (s.top() == '/' || s.top() == '*' || s.top() == '-' || s.top() == '+')) || (str[i] == '/' && (s.top() == '*' || s.top() == '-' || s.top() == '+')) || (str[i] == '*' && (s.top() == '-' || s.top() == '+')) || (str[i] == '-' && (s.top() == '+')) )
            {
                s.push(str[i]);
            }
            else if(str[i] == s.top())
            {
                cout<<s.top();
                s.pop();
                s.push(str[i]);
            }
            else
            {
                cout<<s.top();
                s.pop();
                i--;
            }
        }
    }
    while(!s.empty())
    {
        if(s.top()=='(')
        {
            s.pop();
            continue;
        }
        else
        {
            cout<<s.top();
            s.pop();
        }
    }
}

int main()
{
    int t;
    cin>>t;
    string str;
    FOR(i,0,t)
    {
        str.erase(0,str.length());
        cin>>str;
        rpn(str);
        cout<<'\n';
    }
}
