#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( typeof((v).begin()) it = v.begin(); it != v.end(); it++ )
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
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll b,e; cin>>b>>e;

		vector< pair<ll,ll> > v[n+1];
		vector<ll> d(n+1,LLONG_MAX);

		while(m--){
			ll x,y,w;
			cin>>x>>y>>w;
			v[x].pb( mp(w,y) );
			v[y].pb( mp(w,x) );
		}

		set< pair<ll,ll> > s;
		d[b] = 0;
		s.insert( mp(d[b],b) );

		while(!s.empty()){
			ll x = s.begin()->S;
			s.erase(s.begin());
			for(auto q : v[x]){
				if(d[x] + q.F < d[q.S]){
					s.erase( mp(d[q.S],q.S) );
					d[q.S] = d[x] + q.F;
					s.insert( mp(d[q.S],q.S) );
				}
			}
		}

		if(d[e] != LLONG_MAX)
			cout<<d[e]<<'\n';
		else
			cout<<"NONE"<<'\n';
	}
}