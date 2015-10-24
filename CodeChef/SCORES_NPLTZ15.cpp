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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main(){
	ll n; cin >> n;
	vector<ll> v;
	FOR(i,1,n){
		ll x; cin >> x;
		v.pb(x);
	}
	sort(all(v));
	cout << v[n-1] << " " << v[n-2];
}