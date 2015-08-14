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

#define INPFILE freopen("input.in","r",stdin)

ll arr[1010] = {0};

int main()
{
    //INPFILE;
    ll t;
    gl(t);
    ll n,k,l;
    while(t--)
    {
        gl(n);gl(k);gl(l); // n-> array size; k-> dividing factor
        ll lc = l;
        ll temp = l;
        for(ll i = n; i >= 1; i--)
        {
            if(i != n)
            {
                temp = lc/k;
                if((temp*k) != lc) //ciel function
                    temp += 1;
                lc = temp;
            }
            ll inter = temp%k;
            if(inter == 0)
                inter = k;
            arr[i] = inter;
        }
        fore(i,1,n)
            cout<<arr[i]<<" ";
        pn;
    }
}
