#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
#define gl(n) cin>>n
#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define endl '\n'

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define boost ios::sync_with_stdio(0)
#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)
#define OUTPFILE freopen("out.txt","w",stdout)

int main()
{
	//INPFILE;
	int t,n,m;
	gi(t);
	while(t--)
	{
		gi(n);
		vll x_pos;
		map<ll,ll> x_pos_sorted;
		pll pval; 
		rep(i,n)
		{
			gi(m);
			ll min_x; // Left most point of the polygon can be found using this.
			rep(j,m)
			{
				gl(pval.fs); gl(pval.sc);
				if(j==0)
					min_x = pval.fs;
				else if(pval.fs < min_x)
					min_x = pval.fs;
			}
			x_pos.pb(min_x); // Maintains the order of the polygons in which it needs to be printed.
			x_pos_sorted[min_x] = 0; // Initialize all these x coordinate values in map
		}
		ll k = 1;
		for(map<ll,ll>::iterator it = x_pos_sorted.begin(); it != x_pos_sorted.end(); ++it )
			it->sc = k++;
		rep(i,n)
			printf("%lld ",n-x_pos_sorted[x_pos[i]]);
		pn;
	}
}