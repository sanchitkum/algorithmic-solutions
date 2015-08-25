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

/*
Logic:
n-th order equation:
Here First order equation!
=> dA/dt = k[A];
=> (ln A) = kt;
=> ln At - ln A0 = kt
=> ln At = kt + ln A0
Now, at t = 0;
At = A0
Also at t = t, At = At, so
k = ln(At/A0)/t
therefore, for a particular At
t = ln(At/A0)/k
*/

int main()
{
    //INPFILE;
    int q,p0,p1,t,p;
    gi(q);
    fore(i,1,q)
    {
        gi(p0); gi(p1); gi(t); gi(p);
        double k,ti,At,A0;
        A0 = p0;
        At = p1; // At given time t
        ti = t;
        k = log(At/A0)/ti;
        At = p; // The desired count, for some time
        ti = log(At/A0)/k;
        printf("Scenario #%lld: %.2f\n",i,ti);
    }
}
