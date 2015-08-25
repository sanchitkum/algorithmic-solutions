using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
#define getmax(a,b) a>b?a:b

int main()
{
    int t;
    ll n,val,sum;
    cin>>t;
    FOR(i,0,t)
    {
        cin>>n;
        vector<ll> men,women;
        sum = 0;
        FOR(i,0,n)
        {
            cin>>val;
            men.push_back(val);
        }
        FOR(i,0,n)
        {
            cin>>val;
            women.push_back(val);
        }
        sort(men.begin(),men.end());
        sort(women.begin(),women.end());
        FOR(i,0,n)
            sum += (men[i]*women[i]);
        cout<<sum<<'\n';
    }
}
