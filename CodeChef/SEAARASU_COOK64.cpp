#include <bits/stdc++.h>
typedef long long ll;
// #define get(a) scanf("%lld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> v;
		FOR(i,1,n){
			ll x; cin >> x;
			v.pb(x);
		}
		sort(all(v));
		ll min_val = v[0];
		FOR(i,0,n-1){
			if(v[i] > min_val){
				if(v[i]%min_val == 0)
					v[i] = min_val;
				else
					v[i] -= (v[i] / min_val) * min_val;
			}
			min_val = min(min_val,v[i]);
		}
		cout << n*min_val << '\n';
	}
}