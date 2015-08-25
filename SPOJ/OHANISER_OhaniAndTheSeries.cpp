#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>=b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>=b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

ll mod = 1e9+7;

/*
Formula:
//http://spoj-solutions.blogspot.in/2014/11/ohaniser-ohani-and-series.html
*/

ll pow_mod(ll base, ll exp)
{
    ll res = 1;
    base = base%mod;
    while(exp)
    {
        if(exp&1)
            res = (res*base) % mod;
        base = (base*base) % mod;
        exp = exp>>1; // Right Shift by one (or) Divide by 2
    }
    return res%mod;
}

int main()
{
    ll t,n;
    gl(t);
    fore(i,1,t)
    {
        gl(n);
        if(n == 1)
            cout<<"Case "<<i<<": "<<1;
        else if(n == 2)
            cout<<"Case "<<i<<": "<<3;
        else
        {
            ll res = ((n+1) * pow_mod(2,n-2))%mod;
            cout<<"Case "<<i<<": "<<res;
        }
        pn;
    }
}
