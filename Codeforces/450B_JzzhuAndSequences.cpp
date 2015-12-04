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

ll mod = (ll) 1e9+7;

int main(){
	ll x,y,n;
	cin >> x >> y >> n;
	vector<ll> v(6);
	v[1] = x;
	v[2] = y;
	FOR(i,2,4)
		v[i+1] = v[i] - v[i-1];
	v[0] = v[5] - v[4]; // For the 6th element
	while(v[n%6] < 0)
		v[n%6] += mod;
	cout << v[n%6] % mod;
}