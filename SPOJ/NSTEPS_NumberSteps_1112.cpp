using namespace std;

#include<iostream>
#include<math.h>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
#define getmax(a,b) a>b?a:b

int main()
{
    int n,x,y;
    cin>>n;
    FOR(i,0,n)
    {
        cin>>x>>y;
        if(x==y)
        {
            if(x%2 == 0)
                cout<<x+y<<'\n';
            else
                cout<<x+y-1<<'\n';
        }
        else if(x == (y+2))
        {
            if(x%2 == 0)
                cout<<x+y<<'\n';
            else
                cout<<x+y-1<<'\n';
        }
        else
            cout<<"No Number"<<'\n';
    }
}
