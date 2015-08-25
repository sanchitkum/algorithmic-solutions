using namespace std;

#include<iostream>

#define ll long long
#define FOR(i,a,b) for( ll i = a; i < b; i++ )

int main()
{
    ll n,t,res;
    cin>>n;
    FOR(i,0,n)
    {
        res = 0;
        cin>>t;
        while(t>0)
        {
            res = res + t/5;
            t = t/5;
        }
        cout<<res<<'\n';
    }
}
