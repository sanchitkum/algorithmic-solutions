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