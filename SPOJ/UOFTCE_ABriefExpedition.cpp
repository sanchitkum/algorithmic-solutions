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

char mat[105][105];
bool mark[105][105];
int dist[105][105];
int ci,cj;
vi distances;

int gx[] = {1,0,-1,0}; // All four direction, (1,0) S ,(0,1) E ,(-1,0) N,(0,-1) W
int gy[] = {0,1,0,-1};

void bfs(int r, int c)
{
    queue< pii > q;
    pii pval;
    pval.fs = ci;
    pval.sc = cj;
    q.push(pval); // Starting point of bfs
    mark[ci][cj] = 1;
    dist[ci][cj] = 0;
    pii temp;
    while(!q.empty())
    {
        pval = q.front();
        q.pop();
        forup(i,0,4)
        {
            temp.fs = pval.fs + gx[i];
            temp.sc = pval.sc + gy[i];
            if(temp.fs >= 0 && temp.fs < r && temp.sc >= 0 && temp.sc < c) // Check that the point lies within the matrix
            {
                if(mat[temp.fs][temp.sc] == 'S' && !mark[temp.fs][temp.sc])
                {
                    q.push(temp);
                    mark[temp.fs][temp.sc] = 1;
                    dist[temp.fs][temp.sc] = dist[pval.fs][pval.sc] + 1;
                    distances.pb(dist[temp.fs][temp.sc]);
                }
                if(mat[temp.fs][temp.sc] != '#' && !mark[temp.fs][temp.sc]) // Not a wall and not visited before
                {
                    q.push(temp);
                    mark[temp.fs][temp.sc] = 1;
                    dist[temp.fs][temp.sc] = dist[pval.fs][pval.sc] + 1; // Increment the distance by 1
                }
            }
        }
    }
}

int main()
{
    //INPFILE;
    int m,r,c;
    gi(m);
    while(m--)
    {
        memset(mark,0,sizeof(mark));
        memset(dist,0,sizeof(dist));
        gi(r); gi(c);
        rep(i,r)
            scanf("%s",mat[i]);
        //rep(i,r)
        //    printf("%s\n",mat[i]);
        int flag = 0;
        distances.clear(); // Clear distances for each new matrix (mall)
        forup(i,0,r) // Find the location of 'C' i.e the car
        {
            forup(j,0,c)
            {
                if(mat[i][j] == 'C')
                {
                    ci = i;
                    cj = j;
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        bfs(r,c);
        sort(all(distances));
        ll res = 0;
        res += (distances.size()*60); // 60 minutes at each shopping store
        for(vi::iterator it = distances.begin(); it != distances.end(); ++it)
            res += (2*(*it)); // Add both the distance from car to shop and shop to car
        res -= distances.back(); // Remove the distance of going from car to shop for the farthest shop (add only once)
        pln(res);
    }
}
