#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
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

int main(){
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> v;
		v.pb(0); // 1 Indexing
		ll sum = 0;
		for(ll i = 0; i < n; i++){
			ll x; cin >> x;
			v.pb(x);
			sum += x;
		}
		
		// Balanced Partition
		ll s_half = sum / 2; // Aim is to reach half the sum
		ll partition[n+1][s_half+1]; // Elements and sum attainable

		for(ll i = 0; i <= n; i++){
			for(ll j = 0; j <= s_half; j++){
				if(i == 0 || j == 0) // Boundary elements, i.e 0 elements in consideration OR 0 sum is required
					partition[i][j] = 0;
				else if(j - v[i] >= 0) // Accesible when we want to check wheather this elements sum can be included or not
					partition[i][j] = max( partition[i-1][j] , partition[i-1][j-v[i]] + v[i] ); // Maximum of sum attainable without and with this element
				else
					partition[i][j] = partition[i-1][j];
			}
		}

		// partition[n][s_half] stores the maximum sum attainble from any subset when all n elemenrs are considered and s_half is the maximum sum we wish for
		ll ans = sum - 2*partition[n][s_half]; 
		cout << ans << '\n';
	}		
}