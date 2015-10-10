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
	ll k,n; cin>>k>>n;

	vector< pair<ll,ll> > v[k+1];
	vector<ll> d(k+1,LLONG_MAX);

	FOR(i,1,n){
		ll x,y,w;
		cin>>x>>y;
		w = (y-x)*5;
		v[x].pb( mp(w,y) );
		v[y].pb( mp(w,x) );
	}

	set< pair<ll,ll> > s;

	//Start from 1st Floor
	d[1] = 0;
	s.insert( mp(d[1],1) );

	while(!s.empty()){
		ll x = s.begin()->S;
		s.erase(s.begin());
		for(auto q : v[x]){
			ll wait;
			if(x < q.S){
				if(d[x] % (2*q.F) == 0)
					wait = 0;
				else
					wait = (2*q.F) - (d[x] % (2*q.F));
			}
			else{
				if( (d[x]/q.F)%2 == 1 && (d[x]%q.F) == 0)
					wait = 0;
				else if( (d[x]/q.F)%2 == 0 )
					wait = q.F - (d[x]%q.F); // In its Direction
				else
					wait = q.F + (q.F - (d[x]%q.F)); // In opposite Direction
			}
			if(d[x] + q.F + wait < d[q.S]){
				s.erase(mp(d[q.S],q.S));
				d[q.S] = d[x] + q.F + wait;
				s.insert(mp(d[q.S],q.S));
			}
		}
	}
	cout<<d[k];
}