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
	ll n,e,t,m;
	cin>>n>>e>>t>>m;

	vector< pair<ll,ll> > v[n+1];
	
	FOR(i,1,m){
		ll x,y,w;
		cin>>x>>y>>w;
		v[x].pb( mp(w,y) );
	}

	ll ans = 0;
	FOR(i,1,n){
		vector<ll> d(n+1,LLONG_MAX);
		set< pair<ll,ll> > s;

		//Start from ith point
		d[i] = 0;
		s.insert(mp(d[i],i));

		while(!s.empty()){
			ll x = s.begin()->S;
			if(x == e){
				if(d[x] <= t)	ans++;
				break;
			}
			s.erase(s.begin());
			for(auto q : v[x]){
				if(d[x] + q.F < d[q.S]){
					s.erase( mp(d[q.S],q.S) );
					d[q.S] = d[x] + q.F;
					s.insert( mp(d[q.S],q.S) );
				}
			}
		}
	}

	cout<<ans;

}