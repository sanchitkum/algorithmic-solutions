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

char mat[30][30];
bool mark[30][30];

void dfs(int r, int c, int i, int j)
{
    if(i < 0 || i>= r || j < 0 || j >= c)
        return;
    mark[i][j] = 1;
    if(!mark[i][j+1] && mat[i][j+1] != '#') // Right
        dfs(r,c,i,j+1);
    if(!mark[i][j-1] && mat[i][j-1] != '#') // Left
        dfs(r,c,i,j-1);
    if(!mark[i+1][j] && mat[i+1][j] != '#') // Down
        dfs(r,c,i+1,j);
    if(!mark[i-1][j] && mat[i-1][j] != '#') // Up
        dfs(r,c,i-1,j);
}

int main()
{
    //INPFILE;
    int t,r,c;
    gi(t);
    while(t--)
    {
        gi(r);gi(c);
        memset(mark,0,sizeof(mark));
        rep(i,r)
            scanf("%s",mat[i]);
        int cnt = 0;
        int si,sj,ei,ej; // si/sj -> start i,j ; ei/ej -> end i,j
        int flag = 0;
        forup(i,0,r) // Traverse the matrix
        {
            forup(j,0,c)
            {
                if(i == 0 || j == 0 || i == r-1 || j == c-1) // If it is boundary
                {
                    if(mat[i][j] == '.') // Check if the boundary is open
                    {
                        cnt++; // Keep a count of number of open points
                        if(!flag) // First encounter note the si and sj
                        {
                            si = i; sj = j;
                        }
                        else // Second encounter note the ei ej
                        {
                            ei = i; ej = j;
                        }
                        flag = 1;
                    }
                }
            }
        }
        if(cnt != 2) // There should be exactly two boundary points in a maze
        {
            printf("invalid\n");
            continue;
        }
        dfs(r,c,si,sj);
        if(mark[ei][ej]) // The end point should be reachable
            printf("valid\n");
        else
            printf("invalid\n");
    }
}
