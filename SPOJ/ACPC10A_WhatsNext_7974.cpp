using namespace std;

#include<iostream>
#include<math.h>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
#define getmax(a,b) a>b?a:b

int main()
{
    ll a,b,c;
    while(true)
    {
        cin>>a>>b>>c;
        if( a == 0 && b == 0 && c == 0 )
            break;
        if( b-a == c-b )
        {
            cout<<"AP ";
            cout<<c+(b-a);
        }
        else if( b/a == c/b )
        {
            cout<<"GP ";
            cout<<c*(b/a);
        }
        cout<<'\n';
    }
}
