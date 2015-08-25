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

int adjmat[255][255] = {0};
bool mark[255][255] = {0};
int slick;
int slick_size;
map<int,int> slick_list;

void dfs_visit(int n, int m, int i, int j);

int dfs(int n, int m)
{
    forup(i,0,n)
    {
        forup(j,0,m)
        {
            if(!mark[i][j] && adjmat[i][j])
            {
                slick++;
                slick_size = 0;
                dfs_visit(n,m,i,j);
                // After return add this slick to the list of slicks
                slick_list[slick_size]++; // Maps are initialized with zero
            }
        }
    }
    return slick;
}

void dfs_visit(int n, int m, int i, int j)
{
    if(i>=n || j>=m || i<0 || j<0) // Check that the new i and j belong inside the matrix
        return;
    slick_size++; // Increment the size of the slick
    mark[i][j] = 1;
    // See in all four directions
    if(!mark[i+1][j] && adjmat[i+1][j]) // Down
        dfs_visit(n,m,i+1,j);
    if(!mark[i][j+1] && adjmat[i][j+1]) // Right
        dfs_visit(n,m,i,j+1);
    if(!mark[i-1][j] && adjmat[i-1][j]) // Up
        dfs_visit(n,m,i-1,j);
    if(!mark[i][j-1] && adjmat[i][j-1]) // Left
        dfs_visit(n,m,i,j-1);

}

int main()
{
    //INPFILE;
    int n,m;
    while(true)
    {
        gi(n); gi(m);
        if(n == 0 && m == 0)
            break;
        memset(mark,0,sizeof(mark));
        slick = 0;
        slick_list.clear();
        forup(i,0,n) // Input the matrix
            forup(j,0,m)
                gi(adjmat[i][j]);
        slick = dfs(n,m);
        pin(slick);
        for(map<int,int>::iterator it = slick_list.begin(); it != slick_list.end(); ++it)
            printf("%d %d\n",it->fs,it->sc);
    }
}
