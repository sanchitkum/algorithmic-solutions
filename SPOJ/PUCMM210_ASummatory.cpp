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
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
//#define gl(n) cin>>n
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
//#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)
#define MOD 1000000003

vll cubesum;
vll sumTillN;

void computeCubeSum() // Calculates f(n) for each n from 1 to n
{
    cubesum.pb(0);
    sumTillN.pb(0);
    ll n = 1000000;
    ll cube,sum,sum_n = 0;
    for(ll i = 1; i<=n; i++)
    {
        cube = i*i*i;
        sum = ( cubesum[i-1] + (cube%MOD) ) % MOD;
        cubesum.pb(sum);
        sum_n = (sum_n + sum) %MOD;
        sumTillN.pb(sum_n);
    }
}

int main()
{
    int t;
    gi(t);
    ll n;
    computeCubeSum();
    while(t--)
    {
        gl(n);
        pln(sumTillN[n]);
    }
}
