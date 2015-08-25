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

int main()
{
    //INPFILE;
    ll n,k,m;
    while(true)
    {
        gl(n); gl(k); gl(m);
        if(n == -1 && k == -1 && m == -1)
            break;
        map<ll,ll> kd; //Map the key with the door
        vll adj[n+1];
        bool mark[n+1];
        bool door[n+1];
        memset(mark,0,sizeof(mark)); //Mark all - unvisited
        memset(door,1,sizeof(door)); //Open all the doors
        ll u,v;
        rep(i,k)
        {
            gl(u); gl(v);
            kd[u] = v;
            door[v] = 0; //Close the door which requires a key
        }

        rep(i,m)
        {
            gl(u); gl(v);
            adj[u].pb(v);
            adj[v].pb(u); //Corridor bidirectional
        }

        // BFS

        queue<ll> q; //All that are possible to visit because UNLOCKED door
        set<ll> unvisited; // All unique unvisited chamber because LOCKED doors
        q.push(1);
        mark[1] = 1;
        ll q_node;
        while(!q.empty())
        {
            q_node = q.front();
            q.pop();
            for(vll::iterator it = adj[q_node].begin(); it != adj[q_node].end(); ++it)
            {
                if(!mark[*it] && door[*it])
                {
                    q.push(*it);
                    mark[*it] = 1;
                    if(kd[*it]) // If there is a key in this chamber for door of another chamber //Map returns 0, if the key doesnt exist!
                        door[kd[*it]] = 1; // Open the door which this key points to!
                }
                else if(!mark[*it])
                {
                    unvisited.insert(*it);
                }
            }
            for(set<ll>::iterator it = unvisited.begin(); it != unvisited.end();)
            {
                if(!mark[*it] && door[*it])
                {
                    q.push(*it);
                    mark[*it] = 1;
                    if(kd[*it]) // If there is a key in this chamber for door of another chamber //Map returns 0, if the key doesnt exist!
                        door[kd[*it]] = 1; // Open the door which this key points to!
                    unvisited.erase(it++); //http://stackoverflow.com/questions/2874441/deleting-elements-from-stl-set-while-iterating
                }
                else
                    ++it;
                /*
                Note that it++ is postfix, hence it passes the old position to erase, but first jumps to a newer one due to the operator!
                */
            }
        }
        if(mark[n])
            printf("Y\n");
        else
            printf("N\n");
    }
}
