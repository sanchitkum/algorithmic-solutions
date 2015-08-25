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
#define gi(n) scanf("%d",&n);
#define gl(n) scanf("%lld",&n);
#define pin(x) printf("%d\n",x);
#define pln(x) printf("%lld\n",x);
#define pn printf("\n");
#define ps printf(" ");

#define fs first
#define sc second
#define pb push_back

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

/*
Logic: Every number above 5 can be represented using 3 and 4, thus they can be brought to zero(0)
Eg:
6 -> 2*3
7 -> 4+3
8 -> 2*4
9 -> 3*3
10 -> 3+4+4, ...
*/

int main()
{
    int t;
    gi(t);
    ll n,v;
    while(t--)
    {
        gl(n);
        rep(i,n)
        {
            gl(v);
            if(v < 0)
            {
                printf("%lld ",v);
                continue;
            }
            if(v <= 2)
            {
                printf("%lld ",v-4);
                continue;
            }
            if(v == 5)
                printf("-3 ");
            else
                printf("-4 "); // All other number like 3,4 and 6,7,8,.. will come to zero and hence -4;
        }
        pn;
    }
}
