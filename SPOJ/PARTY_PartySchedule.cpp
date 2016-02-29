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
	while(true){
		ll c,n; cin >> c >> n;
		if(c == 0 && n == 0)
			break;
		vector< pair<ll,ll> > v(n+1);
		for(ll i = 1; i <= n; i++)
			cin >> v[i].first >> v[i].second;

		ll dp[n+1][c+1]; // item and cost
		for(ll i = 0; i <= n; i++) // initialization for 0 cost, fun will be 0
			dp[i][0] = 0;
		for(ll i = 0; i <= c; i++) // initialization for 0 item, fun will be 0
			dp[0][i] = 0;

		for(ll i = 1; i <= n; i++){ // For each item, should be included or not
			for(ll j = 1; j <= c; j++){
				if(j - v[i].first < 0) // Too costly
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = max(dp[i-1][j], v[i].second + dp[i-1][j-v[i].first]);
			}
		}
		ll max_fun = dp[n][c];
		ll max_cost;
		for(ll i = 0; i <= c; i++){
			if(dp[n][i] == max_fun)
				{ max_cost = i; break; }
		}
		cout << max_cost << " " << max_fun << '\n';
	}	
}