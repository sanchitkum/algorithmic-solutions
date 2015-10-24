#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define F first
#define S second
#define mp make_pair
using namespace std;

int main(){
	ll n; cin >> n;
	vector<ll> v;
	FOR(i,1,n){
		ll x; cin >> x;
		v.pb(x);
	}
	vector<ll> max_v(n+1,0);
	max_v[0] = 1;
	max_v[1] = 2;

	FOR(i,2,n-1){
		if(v[i] == v[i-1] + v[i-2])
			max_v[i] = max_v[i-1] + 1;
		else
			max_v[i] = 2;
	}
	ll ans = LLONG_MIN;
	FOR(i,0,n-1){
		ans = max(ans,max_v[i]);
	}
	cout << ans;
}