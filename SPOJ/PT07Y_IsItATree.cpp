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
First check the condition that number of edges is one less than nodes , i.e, m = n-1;
DFS/BFS the given graph, if all nodes are visited then it is a tree!
If there exists a unvisited node, it means it a disconnected graph, i.e, it is not a tree
*/

void dfs(vll adj[], int root, bool mark[])
{
    mark[root] = 1;
    for(vll::iterator it = adj[root].begin(); it != adj[root].end(); ++it)
        if(!mark[*it])
            dfs(adj,*it,mark);
}

int main()
{
    int n,m;
    gi(n); gi(m);
    int u,v;
    vll adj[n+1];
    bool mark[n+1];
    memset(mark,0,sizeof(mark));
    rep(i,m)
    {
        gi(u);gi(v);
        adj[u].pb(v);
        adj[v].pb(u); // Undirected
    }
    if(m != n-1) // Can be a tree only when number of edges is n-1
    {
        printf("NO\n");
        return 0;
    }
    dfs(adj,1,mark);
    int flag = 0;
    fore(i,1,n)
    {
        if(!mark[i]) // If any node is unvisited then, it is not a tree, but is a disconnected graph
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        printf("NO\n");
    else
        printf("YES\n");
}
