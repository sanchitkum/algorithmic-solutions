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
#define gl(n) cin>>x
#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define endl '\n'

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define boost ios::sync_with_stdio(0)
#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin); freopen("out.txt","w",stdout)

map<ll,ll> coinVal;

ll coins(ll n)
{
    if(n == 0) // Since coinVal of 0 is 0 // Exception case
    	return 0;
    if(coinVal[n])
    	return coinVal[n];
    ll x,y,z;
    x = n/2;
    y = n/3;
    z = n/4;
    coins(x);
    coins(y);
    coins(z);
    coinVal[n] = max(n,coinVal[x]+coinVal[y]+coinVal[z]);
    return coinVal[n];
}

int main()
{
    ll n;
    while(scanf("%lld",&n)>0)
    {
        cout<<coins(n); pn;
    }
}
