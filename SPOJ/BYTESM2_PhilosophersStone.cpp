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

ll arr[101][101];
ll dp[101][101];
ll h,w;

ll dfs(int x, int y);

ll dfs_visit(){ // Starting each point the first row
	ll ans = LLONG_MIN;
	for(int i = 0; i < w; i++){
		ans = max(ans,dfs(0,i));
	}
	return ans;
}

ll dfs(int x, int y){
	if(x >= h || y >= w || x < 0 || y < 0)
		return 0;
	if(dp[x][y] != -1)
		return dp[x][y];

	ll ans = 0;
	ll val = arr[x][y];

	ans = max(ans, val + dfs(x+1,y-1)); // Go down left
	ans = max(ans, val + dfs(x+1,y)); // Go down
	ans = max(ans, val + dfs(x+1,y+1)); // Go down right
	
	dp[x][y] = ans;
	return dp[x][y];
}

int main(){
	ll t; cin >> t;
	while(t--){
		cin >> h >> w;
		FOR(i,0,h-1)
			FOR(j,0,w-1)
				cin >> arr[i][j];
		memset(dp,-1,sizeof(dp));
		ll ans = dfs_visit();
		cout << ans << '\n';
	}	
}