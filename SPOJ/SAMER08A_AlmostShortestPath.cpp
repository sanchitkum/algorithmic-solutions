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

int main(){
	while(true){
		ll n,m; cin>>n>>m;
		if(n == 0 && m == 0)
			break;

		vector< pair<ll,ll> > v[n];
		vector<ll> d(n,LLONG_MAX); // Distance
		vector<ll> p(n,-1); // Parent

		ll S,D; cin>>S>>D;

		ll x,y,w;
		FOR(i,1,m){
			cin>>x>>y>>w;
			v[x].pb( mp(w,y) );
		}

		set< pair<ll,ll> > s;
		//Starting from S;
		d[S] = 0;
		s.insert( mp(d[S],S) );

		while(!s.empty()){
			x = s.begin()->S;
			s.erase(s.begin());
			for( vector< pair<ll,ll> >::iterator it = v[x].begin(); it != v[x].end(); ++it){
				if(d[x] + it->F < d[it->S]){
					s.erase( mp(d[it->S],it->S) );
					d[it->S] = d[x] + it->F;
					p[it->S] = x;
					s.insert( mp(d[it->S],it->S) );
				}
			}
		}

		if(d[D] == LLONG_MAX)
			{ cout<<"-1\n"; continue; }

		ll short_path = d[D];

		do{
			// Run the Dijkstra again
			fill(all(d),LLONG_MAX);
			fill(all(p),-1);
			s.clear();

			//Starting from S;
			d[S] = 0;
			s.insert( mp(d[S],S) );

			set< pair<ll,ll> > edge; // edges that need to be deleted

			while(!s.empty()){
				x = s.begin()->S;
				s.erase(s.begin());
				//debug(x);
				if(x == D && d[D] == short_path){ // Each time you find shortest path, insert the edges involved
					ll ptr = D;
					while(p[ptr] != -1){
						x = p[ptr]; y = ptr;
						edge.insert( mp(x,y) );
						ptr = p[ptr];
					}
				}
				for( vector< pair<ll,ll> >::iterator it = v[x].begin(); it != v[x].end(); ++it){
					//cout<<"Before Update: "<<d[it->S]<<" The node: "<<it->S<<'\n';
					if(d[x] + it->F < d[it->S]){
						//s.erase( mp(d[it->S],it->S) );
						d[it->S] = d[x] + it->F;
						p[it->S] = x;
						s.insert( mp(d[it->S],it->S) );
						//cout<<"AFTER Update: "<<d[it->S]<<" The node: "<<it->S<<'\n';
					}
					else if(d[x] + it->F == d[it->S]){ //Update the parent on again seeing the same distance
						p[it->S] = x;
						//cout<<"Updated Parent\n";
					}
				}
			}

			//Erase all those edges that contributed to shortest path
			for( set< pair<ll,ll> >::iterator s_it = edge.begin(); s_it != edge.end(); ++s_it ){
				//debug(s_it->F); debug(s_it->S);
				for( vector< pair<ll,ll> >::iterator it = v[s_it->F].begin(); it != v[s_it->F].end(); ++it){
					if(it->S == s_it->S)
						{ v[s_it->F].erase(it); break; }
				}
			}
		}while(d[D] == short_path);

		// Final Dijkstra for finding the almost shortest path
		fill(all(d),LLONG_MAX);
		fill(all(p),-1);
		s.clear();

		//Starting from S;
		d[S] = 0;
		s.insert( mp(d[S],S) );

		while(!s.empty()){
			x = s.begin()->S;
			s.erase(s.begin());
			for( vector< pair<ll,ll> >::iterator it = v[x].begin(); it != v[x].end(); ++it){
				if(d[x] + it->F < d[it->S]){
					s.erase( mp(d[it->S],it->S) );
					d[it->S] = d[x] + it->F;
					p[it->S] = x;
					s.insert( mp(d[it->S],it->S) );
				}
			}
		}

		if(d[D] != LLONG_MAX)
			cout<<d[D]<<'\n';
		else
			cout<<"-1\n";
	}
}