#include <bits/stdc++.h>

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
#define gl(n) scanf("%lld",&n)

#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

int main()
{
    ll t;
    gl(t);
    while(t--)
    {
        ll n,val;
        gl(n);
        vll vf,vb;
        rep(n)
        {
            gl(val);
            vf.pb(val);
        }
        rep(n)
        {
            gl(val);
            vb.pb(val);
        }
        ll d;
        gl(d);
        ll minval,res,reachedval;
        minval = 1000000000000000010;
        rep(n)
        {
            if( (d-vf[i]) < 0)
                val = d;
            else
            {
                val = (vf[i]+vb[i]) * ceil((double)(d-vf[i]) / (vf[i]-vb[i]));
                reachedval = ceil((double)(d-vf[i]) / (vf[i]-vb[i])) * (vf[i]-vb[i]);
                val += (d-reachedval);
            }
            //cout<<val;pn;
            if(val < minval)
            {
                minval = val;
                res = i+1;
            }
        }
        pln(res);
    }
}
