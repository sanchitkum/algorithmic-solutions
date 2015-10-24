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
	ll n,l; cin >> n >> l;
	vector<ll> v;
	FOR(i,1,n){
		ll x; cin >> x;
		v.pb(x);
	}
	sort(all(v));
	double max_val = DBL_MIN;

	double start = v[0] - 0;
	max_val = max(max_val,start);
	double end = l - v[v.size()-1];
	max_val = max(max_val,end);

	FOR(i,1,v.size()-1){
		double val = ((double)v[i] - v[i-1])/2;
		max_val = max(max_val,val);
	} 

	printf("%.10lf", max_val);
}