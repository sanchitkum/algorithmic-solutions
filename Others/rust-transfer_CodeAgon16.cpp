#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

#define INF 99999999

struct edge{
	ll x,y;
	ll r,t;
};

void dijkstra(vector< pair<ll,ll> > adj[], vector<ll> &d, ll S){
	d[S] = 0; // distance of source is 0
	set< pair<ll,ll> > s;
	s.insert( mp(d[S],S) ); // pair<weight, source>
	
	ll u;

	while(!s.empty()){
		u = s.begin()->S;
		s.erase(s.begin());
		for(auto q : adj[u]){
			ll cost = q.F;
			ll v = q.S;
			if(d[u] + cost < d[v]){
				s.erase( mp(d[v],v) );
				d[v] = d[u] + cost;
				s.insert( mp(d[v],v) );
			}
		}
	}
}

int main(){
	// INPFILE;
	int t; cin >> t;
	while(t--){
		ll n,m; cin >> n >> m;
		
		vector< pair<ll,ll> > adj[n+1];
		vector<ll> dS(n+1,INF);
		vector<ll> dD(n+1,INF);
		edge e[m+1];
		ll x,y,r,t;

		FOR(i,1,m){
			cin >> x >> y >> r >> t;
			e[i].x = x;
			e[i].y = y;
			e[i].r = r;
			e[i].t = t;
			adj[x].pb( mp(r,y) );
			adj[y].pb( mp(r,x) );
		}

		ll S,D; cin >> S >> D;
		
		dijkstra(adj,dS,S);
		dijkstra(adj,dD,D);
		ll ans = dS[D];
		// debug(ans);

		FOR(i,1,m){
			x = e[i].x; y = e[i].y; t = e[i].t;
			// cerr << "dS[x]: " << dS[x] << " + t: " << t << " + dD[y]: " << dD[y] << " = " <<   dS[x] + t + dD[y] << '\n';
			ans = min(ans, dS[x] + t + dD[y] );
			ans = min(ans, dS[y] + t + dD[x] );
			// debug(ans);
		}
		if(ans != INF)
			cout << ans << '\n';
		else
			cout << "-1\n";
	}	
}