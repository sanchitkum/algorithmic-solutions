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
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
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

int main()
{
    int t;
    gi(t);
    while(t--)
    {
        int n1,n2,val;
        ll mindif = 1000005;
        vi v1,v2;
        gi(n1);
        rep(n1)
        {
            gi(val);
            v1.pb(val);
        }
        gi(n2);
        rep(n2)
        {
            gi(val);
            v2.pb(val);
        }
        ll diff;
        forup(i,0,n1)
        {
            forup(j,0,n2)
            {
                diff = v2[j]-v1[i];
                if( absol( diff ) < mindif )
                    mindif = absol( diff );
            }
        }
        pln(mindif);
    }
}
