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
		ll e,f; cin >> e >> f;
		ll w = f - e;
		ll n; cin >> n;
		vector< pair<ll,ll> > v(n+1); // value, weight
		for(ll i = 1; i <= n; i++)
			cin >> v[i].first >> v[i].second;
		vector<ll> dp(w+1,INT_MAX);
		dp[0] = 0;
		for(ll i = 1; i <= w; i++){ // For each weight
			for(ll j = 1; j <= n; j++){ // Each coin
				if(i - v[j].second < 0)
					continue;
				else
					dp[i] = min( dp[i], dp[i-v[j].second] + v[j].first );
			}
		}
		if(dp[w] >= INT_MAX)
			cout << "This is impossible.\n";
		else
			cout << "The minimum amount of money in the piggy-bank is " << dp[w] << ".\n";
	}	
}