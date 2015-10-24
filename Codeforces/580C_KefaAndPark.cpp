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

ll n,m; 
vector<ll> adj[100005];
vector<ll> mark(100005,0);
vector<ll> state(100005,0);
ll ans = 0;

void dfs(ll root, ll cnt){
	mark[root] = 1;
	if(state[root])
		cnt++;
	else
		cnt = 0;
	if(cnt > m) {
		return;
	}
	
	int flag = 1;
	for(auto q : adj[root]) {
		if(!mark[q]){
			flag = 0;
			dfs(q,cnt);
		}
	}

	if(flag)
		ans++;
	mark[root] = 0;
}

int main() {

	cin >> n >> m;

	FOR(i,1,n){
		cin >> state[i];
	}

	FOR(i,1,n-1){
		ll x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	ll cnt = 0;
	dfs(1,cnt);

	cout << ans;

}