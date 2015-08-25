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
Logic:
Since Unweighted and Undirected TREE (Only one path), the BFS will give the count of edges (distance) between two points!

This problem can be solved using two BFS. Use a BFS to search maximum distant leaf node from any intermediate arbitrary node &
then again use BFS from leaf node to traverse the graph and find the maximum distant leaf node.

Link to proof: http://apps.topcoder.com/forums/?module=Thread&threadID=794604&start=0&mc=3#1758019
Code: http://spoj-solutions.blogspot.in/2014/08/pt07z-longest-path-in-tree.html
*/

int main()
{
    int n; // n - nodes
    gi(n);

    vll adj[n+1]; // TO make it 1-based graph (not 0 based)
    bool mark[n+1];
    vll dist(n+1,0); // Distance of each node from the source
    memset(mark,0,sizeof(mark));
    ll u,v;

    rep(i,n-1) // For N nodes there are N-1 edges!
    {
        gl(u); gl(v);
        adj[u].pb(v);
        adj[v].pb(u); // Since Undirected
    }

    // BFS
    queue<ll> q;
    q.push(1); // Node one is the arbitrary node
    dist[1] = 0;
    mark[1] = 1;

    ll node_temp;
    while(!q.empty())
    {
        node_temp = q.front();
        for( vll::iterator it = adj[node_temp].begin(); it != adj[node_temp].end(); ++it)
        {
            if(!mark[*it]) // If not explored
            {
                q.push(*it);
                mark[*it] = 1;
                dist[*it] = dist[node_temp] + 1; // Distance is one more than the previous(parent)
            }
        }
        q.pop();
    }
    //Till here we found the leaf node farthest from any arbitrary node
    //Assume this node to be the root node
    memset(mark,0,sizeof(mark));
    memset(&dist[0],0,sizeof(dist[0])*dist.size());

    //Another BFS will give the longest path

    q.push(node_temp); // node_temp is the last node traversed in upper bfs, so must be a leaf node
    dist[node_temp] = 0;
    mark[node_temp] = 1;

    while(!q.empty())
    {
        node_temp = q.front();
        for( vll::iterator it = adj[node_temp].begin(); it != adj[node_temp].end(); ++it)
        {
            if(!mark[*it]) // If not explored
            {
                q.push(*it);
                mark[*it] = 1;
                dist[*it] = dist[node_temp] + 1; // Distance is one more than the previous(parent)
            }
        }
        q.pop();
    }

    cout<<dist[node_temp];pn;
}
