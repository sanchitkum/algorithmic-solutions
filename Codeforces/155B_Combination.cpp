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
	vector< pair<ll,ll> > v;
	FOR(i,1,n){
		ll x,y; cin >> x >> y;
		v.pb(mp(y,x));
	}
	sort(v.rbegin(),v.rend());
	ll cnt = 1;
	ll i = 0;
	ll ans = 0;
	while(cnt >= 1 && i < n){
		cnt += (v[i].F - 1);
		ans += v[i].S;
		i++;
	}
	cout << ans;
}