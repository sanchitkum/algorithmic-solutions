#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )

#define gi(n) scanf("%d",&n)
//#define gl(n) cin>>n
#define gl(n) scanf("%lld",&n)

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

#define INPFILE freopen("input.in","r",stdin)

int main()
{
    //INPFILE;
    int t,si,co,k;
    cin>>t;
    unsigned long long ans = 0;
    forup(i,0,t)
    {
        cin>>si>>co>>k;
        ans = 0;
        if( si-k >= 0 )
        {
            ans += ( 1ULL<<(si-k+1) ) + 1;
            if( co > si-k )
                ans += ( 1ULL<<(si-k+1) );
        }

        if(k == 1) // Handle 'K' is 1 explicitly
        {
            if(si < co)
                ans = 2 * ( (1ULL<<co) - 1);
            else if (si > co)
                ans = (1ULL<<si) + 1;
            if(si!=0 && si<co)
                ans+=3;
        }

        cout<<ans<<'\n';
    }
}
