#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define forup(i,a,b) for( ll i=a; i<b; i++)
#define fordn(i,a,b) for( ll i=a; i>b; i--)
#define fore(i,a,b) for( ll i=a; i<=b; i++)
#define rep(i,a) for(ll i=0; i<n; i++)

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
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define MOD 1000000007

int main()
{
    int t;
    ll n,k;
    gi(t);
    while(t--)
    {
        gl(n); gl(k);
        ll max_profit = 0;
        ll time[n],profit[n];
        rep(i,n)
            gl(time[i]);
        rep(i,n)
        {
            gl(profit[i]);
            ll val = k/time[i];
            max_profit = max(max_profit, val*profit[i]);
        }
        pln(max_profit);
    }
}
