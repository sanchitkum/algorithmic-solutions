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
	ll n,t; cin >> n >> t;
	vector<ll> v;
	FOR(i,1,n){
		ll x; cin >> x;
		v.pb(x);
	}

	ll maxbooks = 0;
	ll currbooks = 0;

	ll sum = 0;
	ll idx = 0;

	FOR(i,0,n-1){
		sum += v[i];
		while(sum > t){
			sum -= v[idx];
			idx++;
			currbooks--;
		}
		currbooks++;
		maxbooks = max(maxbooks,currbooks);
	}
	cout << maxbooks;
}