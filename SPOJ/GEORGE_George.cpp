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

vector< pair<ll,ll> > v[1005];

int main(){
	ll n,m;
	cin>>n>>m;
	ll a,b,k,g;
	cin>>a>>b>>k>>g;

	ll val;
	vector<ll> george;

	vector< pair< pair<ll,ll>,ll > > t[1005]; // t maintains the u -> v and the start and end timing

	ll st = -k; // George start time
	ll et = -k; // George end time

	FOR(i,1,g){
		cin>>val; george.pb(val);
	}

	ll x,y,w;
	FOR(i,1,m){
		cin>>x>>y>>w;
		v[x].pb( mp(w,y) );
		v[y].pb( mp(w,x) );
	}

	FOR(i,1,g-1){
		for( auto q : v[ george[i-1] ]){
			if(q.S == george[i])
				val = q.F;
		}
		//debug(val);
		et += val;
		t[george[i-1]].pb( mp( mp(st,et),george[i]) );
		t[george[i]].pb( mp( mp(st,et),george[i-1]) );
		st += val;
	}

	set< pair<ll,ll> > s;
	vector<ll> d(n+1,LLONG_MAX);

	//Luka Starts from a
	d[a] = 0;
	s.insert( mp(0,a) );

	while(!s.empty()){
		x = s.begin()->S;
		s.erase(s.begin());
		for(auto q : v[x]){
			bool flag = false;
			for( auto r : t[x] ){
				if(r.S == q.S){
					if(d[x] >= r.F.F && d[x] < r.F.S){
						val = r.F.S - d[x];
						flag = true;
						if( d[x] + q.F + val < d[q.S] ){
							s.erase( mp(d[q.S],q.S) );
							d[q.S] = d[x] + q.F + val;
							s.insert( mp(d[q.S],q.S) );
						}
					}
				}
			}
			if(!flag){
				if( d[x] + q.F < d[q.S] ){
					s.erase( mp(d[q.S],q.S) );
					d[q.S] = d[x] + q.F;
					s.insert( mp(d[q.S],q.S) );
				}
			}
		}
	}

	cout<<d[b];

}