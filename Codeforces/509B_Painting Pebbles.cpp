#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
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

#define pin(x) printf("%d\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

int main()
{
    int n,k,val;
    gi(n); gi(k);
    vi v;
    rep(n)
    {
        gi(val);
        v.pb(val);
    }
    vi v2 = v;
    sort( all(v2) );
    if( ( (v2[n-1]/k) - (v2[0]/k) >=2 ) || (((v2[n-1]/k) - (v2[0]/k) >=1) && ((v2[n-1]%k) - (v2[0]%k) >=1) ) )
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        rep(n)
        {
            int no = v[i]/k;
            int rem = v[i]%k;
            fore(j,1,k)
            {
                forup(l,0,no)
                {
                    cout<<j;ps;
                }
                if(rem > 0)
                {
                    cout<<j;ps;
                    rem--;
                }
            }
            pn;
        }
    }
}
