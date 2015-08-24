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
#define gl(n) cin>>n
#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

int main()
{
    ll n,k,p,x,y;
    cin>>n>>k>>p>>x>>y;
    ll instance;
    ll sum = 0;
    ll less_y = 0;
    ll gret_y = 0;
    rep(i,k)
    {
        cin>>instance;
        sum += instance;
        if(instance < y)
            less_y++;
        else
            gret_y++;
    }
    if(less_y > (n/2)) // n is always odd
    {
        cout<<"-1";
        return 0;
    }
    if(sum + (n-k) > x)
    {
        cout<<"-1";
        return 0;
    }
    ll remaining_sum = x - sum;
    ll more = 0;
    if( y != 1 )
        more = (remaining_sum - (n-k)) / (y-1);
    else
        more = (n-k);
    if( (gret_y + more) <= n/2 )
    {
        cout<<"-1";
        return 0;
    }
    ll upto = ((n+1)/2) - gret_y;
    if(upto < 0) upto = 0;
    fore(i,1,upto)
        {cout<<y;ps;}
    fore(i,1,n-k-upto)
        {cout<<"1";ps;}
    return 0;
}
