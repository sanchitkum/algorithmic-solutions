#include <bits/stdc++.h>
typedef long long ll;
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
	ll n, d;
	cin >> n >> d;
	vector< pair<ll,ll> > v;
	vector<ll> sum(n+1,0);
	vector<ll> money;
	FOR(i,1,n){
		ll x,y;
		cin >> x >> y;
		money.pb(x);
		v.pb(mp(x,y));
	}
	sort(all(money));
	sort(all(v));

	sum[0] = v[0].S;
	FOR(i,1,n-1){
		sum[i] = sum[i-1] + v[i].S;
		//debug(sum[i]);
	}

	ll ans = LLONG_MIN;
	FOR(i,0,n-1){
		ll amount = money[i] + d - 1;
		//debug(amount);
		ll idx = upper_bound(all(money),amount) - money.begin() - 1;
		//debug(idx);
		ll val;
		if(i != 0)
			val = sum[idx]-sum[i-1];
		else
			val = sum[idx];
		ans = max(ans,val);
		//debug(ans);
	}

	cout << ans;
}
