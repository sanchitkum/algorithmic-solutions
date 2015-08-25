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
//#define repVector(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); ++it )

#define INPFILE freopen("input.in","r",stdin)

ll cnt;

void dfs_visit(vll adj[], ll root, bool mark[]);

void dfs(vll adj[], bool mark[], int n)
{
    forup(i,0,n)
        if(!mark[i])
        {
            cnt++;
            dfs_visit(adj,i,mark);
        }
}

void dfs_visit(vll adj[], ll root, bool mark[])
{
    mark[root] = 1;
    for(vll::iterator it = adj[root].begin(); it!=adj[root].end(); ++it )
        if(!mark[*it])
            dfs_visit(adj,*it,mark);
}

int main()
{
    int t;
    gi(t);
    while(t--)
    {
        cnt = 0;
        ll n,e;
        gl(n);gl(e);
        vll adj[n];
        bool mark[n];
        memset(mark,0,sizeof(mark));
        ll u,v;
        rep(i,e)
        {
            gl(u);gl(v);
            adj[u].pb(v);
            adj[v].pb(u); // Friends with each other
        }
        dfs(adj,mark,n);
        pln(cnt);
    }
}
