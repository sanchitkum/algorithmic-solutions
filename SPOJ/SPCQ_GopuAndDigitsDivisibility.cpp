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
    //INPFILE;
    int t;
    gi(t);
    ll n,nc;
    int rem,sum,flag;
    while(t--)
    {
        gl(n);
        flag = 0;
        while(flag == 0)
        {
            nc = n;
            sum = 0;
            while(nc != 0)
            {
                rem = nc % 10;
                sum += rem;
                nc /= 10;
            }
            if(n%sum == 0)
            {
                cout<<n;pn;
                flag = 1;
            }
            else
                n++;
        }
    }
}
