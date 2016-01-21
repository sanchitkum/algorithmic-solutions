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

int m,n;
ll dp[201][201][2];
vector<string> v;

ll dfs(int x, int y, int dir){
	if(x >= m || y >= n || x < 0 || y < 0 || v[x][y] == '#')
		return 0;
	if(dp[x][y][dir] != -1)
		return dp[x][y][dir];

	ll ans = 0; // For this particular DP state
	ll tree_cut = 0;
	if(v[x][y] == 'T')
		tree_cut = 1;

	if(dir){ // Right
		ans = max(ans, tree_cut + dfs(x,y+1,dir)); // Go right
		ans = max(ans, tree_cut + dfs(x+1,y,0)); // Go down and face left
	}
	else{
		ans = max(ans, tree_cut + dfs(x,y-1,dir)); // Go left
		ans = max(ans, tree_cut + dfs(x+1,y,1)); // Go down and face right
	}

	dp[x][y][dir] = ans;
	return dp[x][y][dir];
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> m >> n;
		v.clear();
		FOR(i,1,m){
			string s; cin >> s;
			v.pb(s);
		}

		memset(dp,-1,sizeof(dp));
		ll res = dfs(0,0,1);
		cout << res << '\n';
	}	
}