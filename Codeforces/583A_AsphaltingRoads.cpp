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
	ll n; cin >> n;
	vector<ll> markh(n+1,0);
	vector<ll> markv(n+1,0);
	FOR(i,1,n*n) {
		ll a,b;
		cin >> a >> b;
		if( markh[a] == 0 && markv[b] == 0 )
			{ cout<< i <<" "; markh[a] = 1; markv[b] = 1; }
	}
}	