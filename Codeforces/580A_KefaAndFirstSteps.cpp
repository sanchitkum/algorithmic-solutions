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

int main() {
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i = 0; i < n; i++) {
		ll x; cin>>x;
		v.push_back(x);
	}
	ll min_ele = LLONG_MIN;
	ll curr = 0;
	ll ans = 0;
	FOR(i,0,n-1){
		if(v[i] >= min_ele){
			min_ele = v[i];
			curr++;
		}
		else{
			min_ele = v[i];
			curr = 1;
		}
		ans = max(ans,curr);
	}
	cout << ans;
}