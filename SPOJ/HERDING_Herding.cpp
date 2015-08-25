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

char str[1001][1001];
bool mark[1001][1001];
ll cnt;

void dfs_visit(int n, int m, int i, int j);

ll dfs(int n, int m)
{
    forup(i,0,n)
        forup(j,0,m)
            if(!mark[i][j])
            {
                cnt++;
                dfs_visit(n,m,i,j);
            }
    return cnt;
}

void dfs_visit(int n, int m, int i, int j)
{
    if(i>=n || i<0 || j>=m || j<0)
        return;
    mark[i][j] = 1;
    //Consider the path that the current point leads to
    if(str[i][j] == 'S' && !mark[i+1][j])
        dfs_visit(n,m,i+1,j);
    if(str[i][j] == 'E' && !mark[i][j+1])
        dfs_visit(n,m,i,j+1);
    if(str[i][j] == 'W' && !mark[i][j-1])
        dfs_visit(n,m,i,j-1);
    if(str[i][j] == 'N' && !mark[i-1][j])
        dfs_visit(n,m,i-1,j);

    //Consider the other paths that could lead to the current point
    if(str[i][j+1] == 'W' && !mark[i][j+1]) // Right element
        dfs_visit(n,m,i,j+1);
    if(str[i][j-1] == 'E' && !mark[i][j-1]) // Left element
        dfs_visit(n,m,i,j-1);
    if(str[i-1][j] == 'S' && !mark[i-1][j]) // North element
        dfs_visit(n,m,i-1,j);
    if(str[i+1][j] == 'N' && !mark[i+1][j]) // South element
        dfs_visit(n,m,i+1,j);
}

int main()
{
    //INPFILE;
    int n,m;
    gi(n); gi(m);
    memset(mark,0,sizeof(mark));
    cnt = 0;
    rep(i,n)
        scanf("%s",str[i]);
    cnt = dfs(n,m);
    pln(cnt);
}
