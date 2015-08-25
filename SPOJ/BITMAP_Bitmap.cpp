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

char mat[200][200];
bool mark[200][200];
int dist[200][200];

int gx[] = {0,1,0,-1}; // All four direction, (1,0) S ,(0,1) E ,(-1,0) N,(0,-1) W
int gy[] = {1,0,-1,0};

int main()
{
    //INPFILE;
    int t,r,c;
    gi(t);
    while(t--)
    {
        gi(r); gi(c);
        memset(mark,0,sizeof(mark));
        memset(dist,0,sizeof(dist));
        int si,sj;
        queue< pii > q;
        pii pval;

        //INPUT
        forup(i,0,r)
            scanf("%s",mat[i]);
        forup(i,0,r)
        {
            forup(j,0,c)
            {
                if(mat[i][j] == '1') //Push all the 1's first into the queue, to handle the closest white cases!
                {
                    pval.fs = i;
                    pval.sc = j;
                    q.push(pval);
                    mark[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }
        //BFS
        pii temp;
        while(!q.empty())
        {
            pval = q.front();
            q.pop();
            forup(i,0,4) // Check in all four directions
            {
                temp.fs = pval.fs + gx[i];
                temp.sc = pval.sc + gy[i];
                if(temp.fs >= 0 && temp.fs < r && temp.sc >= 0 && temp.sc <c ) // Check that point lies inside matrix
                {
                    if(!mark[temp.fs][temp.sc]) // If not explored
                    {
                        q.push(temp);
                        mark[temp.fs][temp.sc] = 1;
                        dist[temp.fs][temp.sc] = dist[pval.fs][pval.sc] + 1;
                    }
                }
            }
        }

        //Print the distances
        forup(i,0,r)
        {
            forup(j,0,c)
                printf("%d ",dist[i][j]);
            pn;
        }
    }
}
