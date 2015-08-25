using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<map>
#include<math.h>
#include<stack>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
//#define getmax(a,b) a>b?a:b
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#define pn printf("\n")
#define ps printf(" ")
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n
#define pb push_back
//#define pie 3.141592653589793238462643383279

int main()
{
    int n;
    while(true)
    {
        gi(n);
        if(n == 0)
            break;
        int last = 0;
        vector <int> v;
        int val;
        FOR(i,0,n)
        {
            cin>>val;
            v.pb(val);
        }
        stack <int> s;
        int flag = 0;
        FOR(i,0,n)
        {
            if(v[i] == last+1)
            {
                last = v[i];
            }
            else if(!s.empty() && s.top() == last+1)
            {
                last = s.top();
                s.pop(); i--;
            }
            else if(s.empty() || ( !s.empty() && v[i]<s.top() ) )
            {
                s.push(v[i]);
            }
            else
            {
                flag = 1;
                cout<<"no\n";
                break;
            }
        }
        if(flag == 0)
            cout<<"yes\n";
    }
}
