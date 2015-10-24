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
	ll n,m; cin >> n >> m;
	vector<ll> v;
	FOR(i,1,n){
		ll x; cin >> x;
		v.pb(x);
	}
	sort(all(v));
	ll sum = 0;
	FOR(i,0,n-1){
		if(m == 0 || v[i] >= 0)
			break;
		sum += (-1*v[i]);
		m--;
	}
	cout << sum;
}