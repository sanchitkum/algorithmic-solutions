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

map<string,ll> mp;
ll key;

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

    ll returnSize(ll p)
    {
        return sz[p];
    }
};

ll mapping(string s)
{
    if(!mp[s])
        mp[s] = key++;
    return mp[s];
}

int main()
{
    //INPFILE;
    int t;
    gi(t);
    ll n;
    while(t--)
    {
        mp.clear();
        key = 1;
        gl(n);
        string s1,s2;
        vector< pair<ll,ll> > connection;
        pair<ll,ll> pval;
        while(n--)
        {
            cin>>s1>>s2;
            pval.fs = mapping(s1);
            pval.sc = mapping(s2);
            connection.pb(pval);
        }
        UF uf(key-1);
        ll i,j,sz;
        forup(k,0,connection.size())
        {
            pval.fs = connection[k].fs;
            pval.sc = connection[k].sc;
            i = uf.find(pval.fs);
            j = uf.find(pval.sc);
            if(i != j)
                uf.merge(i,j);
            sz = max(uf.returnSize(i),uf.returnSize(j));
            pln(sz);
        }
    }
}
