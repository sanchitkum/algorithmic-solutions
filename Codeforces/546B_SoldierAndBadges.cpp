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
#define gl(n) cin>>n
#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

int main()
{
    ll n,val;
    gl(n);
    vi v;
    bool mark[n+3001];
    fore(i,0,n+3000)
        mark[i] = false;
    v.pb(0);
    rep(i,n)
    {
        gl(val);
        v.pb(val);
        mark[val] = true;
    }
    sort(all(v));
    ll markedtill = 1;
    ll cnt = 0;
    fore(i,2,n)
    {
        if(v[i] == v[i-1])
        {
            fore(j,markedtill,n+3000)
            {
                if(mark[j] == false && j > v[i])
                {
                    markedtill = j;
                    mark[j] = true;
                    cnt += (j-v[i]);
                    //cout<<"v[i],j: "<<v[i]<<" "<<j;pn;
                    //cout<<"C: "<<cnt;pn;
                    break;
                }
            }
        }
    }
    pln(cnt);
}
