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

#define matrix vector< vector<ll> >
#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define MOD 1000000007

#define INPFILE freopen("input.in","r",stdin)

int main()
{
    //INPFILE;
    int t,n;
    gi(t);
    while(t--)
    {
        gi(n);
        int flag = 0;
        ll r,R;
        vll rr,RR;
        fore(i,1,n)
        {
            gl(r); gl(R);
            rr.pb(r);
            RR.pb(R);
        }
        int pos = 1;
        ll maxr = 0;
        forup(i,0,n)
            if( rr[i] > maxr )
            {
                pos = i;
                maxr = rr[i];
            }
        ll maxR = 0;
        forup(i,0,n)
            if( RR[i] > maxR )
            {
                if( i != pos ) // Dont check the outer radious for that particular position (distraction ring), as it doesnt matter
                    maxR = RR[i];
            }
        if(maxR < maxr) // Outer radious is less than inner radious
            pin(pos+1);
        else
            pin(-1);
    }
}
