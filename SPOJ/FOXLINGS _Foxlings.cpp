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
#define gl(n) scanf("%lld",&n)
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

// https://www.quora.com/How-do-you-solve-SPOJ-com-Problem-FOXLINGS-without-getting-a-TLE
// DFS Logic -> Giving SIGSEGV due to large array size! Can be handled using the logic mentioned in above link

ll cnt = 0;
ll n,m;
map<ll,ll> mp;
int key = 1; // Used for mapping and keeps a count of unique vertices with edges

void dfs(ll x, vll adj[], bool mark[]);

void dfs_visit(vll adj[], bool mark[])
{
    fore(i,1,key-1)
    {
        if(!mark[i])
        {
            cnt++;
            dfs(i,adj,mark);
        }
    }
}

void dfs(ll x, vll adj[], bool mark[])
{
    mark[x] = true;
    repIt(adj[x])
        if(!mark[*it])
            dfs(*it,adj,mark);
}

ll mapping(ll u)
{
    if(!mp[u])
        mp[u] = key++;
    return mp[u];
}

int main()
{
    gl(n); gl(m);
    cnt = 0;
    vector< pair<ll,ll> > edge;
    pair<ll,ll> pval;

    rep(i,m)
    {
        gl(pval.fs); gl(pval.sc);
        pval.fs = mapping(pval.fs);
        pval.sc = mapping(pval.sc);
        edge.pb(pval);
    }

    vll adj[key];
    bool mark[key];
    memset(mark,0,sizeof(mark));

    rep(i,m)
    {
        pval = edge[i];
        adj[pval.fs].pb(pval.sc);
        adj[pval.sc].pb(pval.fs);
    }

    dfs_visit(adj,mark);
    ll ans = (n - (key-1)) + cnt;
    pln(ans);
}

/*
// Union Find -> Issue with large allocation of memory
class UF
{
    ll *sz,cnt,*id;
public:
    UF(ll n)
    {
        cnt = n;
        sz = new ll[n+1];
        id = new ll[n+1];
        for(int i = 0; i<=n; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }

    ~UF()
    {
        delete [] sz;
        delete [] id;
    }

    ll find(ll p)
    {
        ll root = p;
        while(root != id[root])
            root = id[root];
        while(p != root) // Flatten the tree
        {
            ll newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }

    void merge(ll p, ll q)
    {
        ll i = find(p);
        ll j = find(q);
        if(i != j)
        {
            if(sz[i] > sz[j])
            {
                id[j] = i;
                sz[i] += sz[j];
            }
            else
            {
                id[i] = j;
                sz[j] += sz[i];
            }
            cnt--;
        }
    }

    bool connected(ll p, ll q)
    {
        return find(p) == find(q);
    }

    ll count()
    {
        return cnt;
    }
};

int main()
{
    //INPFILE;
    ll n,m;
    gl(n); gl(m);
    UF uf(n);
    ll u,v;
    rep(i,m)
    {
        gl(u); gl(v);
        uf.merge(u,v);
        //pln(uf.count());
    }
    pln(uf.count());
}
*/
