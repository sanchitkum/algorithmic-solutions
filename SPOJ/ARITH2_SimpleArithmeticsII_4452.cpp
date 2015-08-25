#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )

#define gi(n) scanf("%d",&n)
#define gl(n) cin>>n

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

ll conv(string s)
{
    ll val = 0;
    forup(i,0,s.length())
    {
        if(!isdigit(s[i]))
            return -1;
        val = val*10 + (s[i] - '0');
    }
    return val;
}

int main()
{
    ll t;
    gl(t);
    while(t--)
    {
        pn;
        string s;
        queue<ll> operands;
        queue<char> operators;
        while(true)
        {
            cin>>s;
            if(s[0] == '=')
                break;
            ll val = conv(s);
            if(val == -1)
                operators.push(s[0]);
            else
                operands.push(val);
        }
        ll res = operands.front();
        operands.pop();
        while(!operators.empty())
        {
            char ch = operators.front();
            operators.pop();
            if(ch == '+')
                res += operands.front();
            else if(ch == '-')
                res -= operands.front();
            else if(ch == '*')
                res *= operands.front();
            else if(ch == '/')
                res /= operands.front();
            operands.pop();
        }
        pln(res);
    }
}
