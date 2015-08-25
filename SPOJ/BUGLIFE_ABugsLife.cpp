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

void bfs_visit(vll adj[], ll node, bool mark[], ll color[],int &flag);

int bfs(vll adj[], bool mark[], ll color[], ll n) // To ensure visiting all nodes in the graph; even disconnected nodes(non interacting bugs)
{
    int flag = 0;
    fore(i,1,n) // To visit all nodes
    {
        if(flag) // If any same coloring is found, break
            break;
        if(!mark[i])
            bfs_visit(adj,i,mark,color,flag); // flag is passed as reference
    }
    return flag; // Returns if the same coloring is present or absent
}

void bfs_visit(vll adj[], ll node, bool mark[], ll color[],int &flag)
{
    // Simple BFS logic
    queue<ll> q;
    q.push(node);
    mark[node] = 1;
    color[node] = 1; // Assign the first node the color '1'
    ll q_node;
    while(!q.empty())
    {
        q_node = q.front();
        q.pop();
        for(vll::iterator it = adj[q_node].begin(); it != adj[q_node].end(); ++it)
        {
            if(mark[*it]) // If the node encountered is already marked, then check for their colors
            {
                if(color[*it] == color[q_node]) // check if their colors are same; if same then they are homosexuals
                {
                    flag = 1; // Mark flag as 1 and break
                    break;
                }
            }
            if(!mark[*it])
            {
                q.push(*it);
                mark[*it] = 1;
                color[*it] = color[q_node] * -1; // For all adjacent nodes assign the opposite color to the parents!
            }
        }
        if(flag) // If any homosexual pair is found, then break;
            break;
    }
}

int main()
{
    int t;
    gi(t);
    fore(k,1,t)
    {
        ll n,e;
        gl(n);gl(e);
        vll adj[n+1];
        bool mark[n+1];
        ll color[n+1];
        memset(mark,0,sizeof(mark));
        memset(color,0,sizeof(color)); // Set the color of all bugs as 0; ; '1' represents M(White) and '-1' represents F(Black)
        ll u,v;
        rep(i,e)
        {
            gl(u); gl(v);
            adj[u].pb(v); // Interaction between bugs
            adj[v].pb(u);
        }
        int flag = bfs(adj,mark,color,n); // flag returns if any same color interaction was found or not!
        if(flag) // Same color found
        {
            printf("Scenario #%d:\n",k);
            printf("Suspicious bugs found!\n");
        }
        else // Same color not found
        {
            printf("Scenario #%d:\n",k);
            printf("No suspicious bugs found!\n");
        }
    }
}
