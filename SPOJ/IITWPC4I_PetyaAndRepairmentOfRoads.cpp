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

class UF
{
    int *id,cnt,*sz;
public:
    UF(int N) // For 1 to N
    {
        cnt = N;
        id = new int[N+1];
        sz = new int[N+1];
        forup(i,0,N+1)
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

    int find(int p)
    {
        int root = p;
        while(root != id[root])
            root = id[root];
        while(p != root)
        {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }

    void merge(int p, int q)
    {
        int i = find(p);
        int j = find(q);
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

    bool connected(int p,int q)
    {
        return find(p) == find(q);
    }

    int count()
    {
        return cnt;
    }
};

struct Edges
{
    int u,v;
    ll weight;
};

bool comp(const Edges u, const Edges v)
{
    return u.weight < v.weight;
}

int main()
{
    int t;
    gi(t);
    ll n,m;
    while(t--)
    {
        gl(n); gl(m);
        int milkman[n+1];
        int flag_milkman = 0; // Whether we encountered any milkman
        int first_milkman = 0; // To merge with this milkman, as we need one reference to merge with
        UF uf(n);
        fore(i,1,n)
        {
            gi(milkman[i]);
            if(milkman[i])
            {
                if(flag_milkman)
                {
                    uf.merge(first_milkman,i);
                }
                else
                {
                    flag_milkman = 1;
                    first_milkman = i;
                }
            }
        }
        vector< Edges > edge;
        Edges edge_instance;
        rep(i,m)
        {
            gi(edge_instance.u); gi(edge_instance.v); gl(edge_instance.weight);
            if(milkman[edge_instance.u] && milkman[edge_instance.v]) // Igneore the edges b/w milkmans
                continue;
            edge.pb(edge_instance);
        }
        sort(all(edge),comp);
        ll cost = 0;
        for(int i=0; i<edge.size();i++)
        {
            if(uf.count() == 1)
                break;
            int p = uf.find(edge[i].u);
            int q = uf.find(edge[i].v);
            if(p != q)
            {
                uf.merge(p,q);
                cost += edge[i].weight;
            }
        }
        if(flag_milkman && uf.count() == 1)
            pln(cost);
        else
            printf("impossible\n");
    }
}
