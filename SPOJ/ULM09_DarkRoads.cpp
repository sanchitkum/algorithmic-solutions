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

/*
Credit[Union Find Data Structure Class]: kartik kukreja
Link: https://github.com/kartikkukreja/blog-codes/blob/master/src/Union%20Find%20(Disjoint%20Set)%20Data%20Structure.cpp
Tutorial: https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
*/

class UF // Union-find data structure
{
    int *id,cnt,*sz;
    /*
    id stores the parent (or the set) which the node belongs to
    cnt maintains the cnt of distinct sets; (initially N)
    sz maintains the size of each node (i.e. that node as root has how many elements)
    */
public:
    UF(int N) // Create an empty union find data structure with N isolated sets.
    {
        cnt = N;
        id = new int[N];
        sz = new int[N];
        for(int i=0; i<N; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }

    ~UF()
    {
        delete [] id;
        delete [] sz;
    }

    int find(int p) // Return the id of component corresponding to object p.
    {
        int root = p;
        while(root != id[root]) // Untill we dicover the representative set
            root = id[root];
        while(p != root) // Flatten the tree, map each node on the path to the root directly
        {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }

    void merge(int p, int q) // Replace sets containing p and q with their union.
    {
        int i = find(p);
        int j = find(q);
        if(i != j) // When they dont belong to the same set, ony then can we perform merge operation
        {
            if(sz[i] > sz[j]) // make smaller root point to larger one
            {
                id[j] = i;
                sz[i] += sz[j]; // Increment the size of the larger tree
            }
            else
            {
                id[i] = j;
                sz[j] += sz[i]; // Increment the size of the larger tree
            }
            cnt--; // After each merge operation the number of disjoint sets decreases
        }
    }

    bool connected(int p, int q) // Are objects x and y in the same set?
    {
        return find(p) == find(q);
    }

    int count() // Return the number of disjoint sets.
    {
        return cnt;
    }
};

struct Edge // representation of undirected edge (u, v) having weight 'weight'
{
    int u,v;
    ll weight;
};

bool comp(Edge *u, Edge *v) // comparator function for sorting edges in ascending order by weight
{
    return u->weight < v->weight;
}

int main()
{
    //INPFILE;
    while(true)
    {
        int V,E,u,v;
        Edge **edges, **mst; // mst will hold the minimum spanning tree;
        // Assuming vertices are labeled 0...V-1

        gi(V); gi(E); // Enter the number of vertices and edges
        if(V == 0 && E == 0)
            break;
        edges = new Edge*[E];
        ll totalcost = 0;
        forup(i,0,E) // Enter E undirected edges (u, v, weight)
        {
            edges[i] = new Edge;
            gi(u); gi(v); gl(edges[i]->weight);
            edges[i]->u = u;
            edges[i]->v = v;
            totalcost += edges[i]->weight;
        }
        sort(edges,edges+E,comp);

        UF uf(V);
        mst = new Edge*[V-1]; // Since there will be V-1 edges if the tree has V vertices;
        ll cost = 0;
        int N = 0;
        ll savedcost = 0;
        for(int i = 0; i < E && N < V-1 ; i++)
        {
            u = edges[i]->u;
            v = edges[i]->v;
            if(!uf.connected(u,v)) // If u,v dont belong to the same set
            {
                uf.merge(u,v);
                mst[N++] = edges[i];
                cost += edges[i]->weight;
            }
//            else // Not included in mst;
//            {
//                savedcost += edges[i]->weight;
//            }
        }
        savedcost = totalcost - cost;
        pln(savedcost);
    }
}
