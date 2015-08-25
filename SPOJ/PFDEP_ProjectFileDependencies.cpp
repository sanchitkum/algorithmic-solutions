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

/*
Logic: Topological Sort (Ordering)
In dfs, the one that finishes first, must be the last to be performed.
The one that finishes later, must be the one that should be performed first.
*/

vi order;
vi adj[105];
bool mark[105];
//bool depend[105];

void dfs_visit(int root);

void dfs(int n)
{
    // Start exploring from the larger nodes, because "tasks that do not depend on each other should be ordered by their number (lower numbers first)"
    for(int i = n; i >= 1; i--)
        if(!mark[i])
            dfs_visit(i);
}

void dfs_visit(int root)
{
    mark[root] = 1;
    for(vi::iterator it = adj[root].begin(); it != adj[root].end(); ++it )
        if(!mark[*it])
            dfs_visit(*it);
    order.pb(root);
}

int main()
{
    //INPFILE;
    int n,m;
    gi(n);gi(m);
    memset(mark,0,sizeof(mark));
    //memset(depend,0,sizeof(depend));
    int u,k,v;
    rep(i,m)
    {
        gi(v); gi(k);
        rep(j,k)
        {
            gi(u);
            adj[u].pb(v); // Directed from u -> v (First u, then v)
        }
        //depend[v] = 1;
    }
    fore(i,1,n)
        sort(all(adj[i]),greater<int>()); // Order from larger to smaller, because we want to explore the larger value first!
    dfs(n);
    for(vi::reverse_iterator it = order.rbegin(); it != order.rend(); ++it) // Print in reverse order
        printf("%d ",*it);
    pn;
}
