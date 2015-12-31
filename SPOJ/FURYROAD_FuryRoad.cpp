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

int arr[1001][1001];
int mark[1001][1001];

int gx[] = {-1,0,1,-1,1,-1,0,1};
int gy[] = {1,1,1,0,0,-1,-1,-1};

void dfs(int x, int y);

bool validate(int x, int y){
	if(x >= 0 && x <= 1000 && y >= 0 && y <= 1000)
		return true;
	return false;
}

ll dfs_visit(){
	ll disjoint_areas = 0;
	for(int i = 0; i <= 1000; i++){
		for(int j = 0; j <= 1000; j++){
			if(arr[i][j] && !mark[i][j]){
				disjoint_areas++;
				dfs(i,j);
			}
		}
	}
	return disjoint_areas;
}

void dfs(int x, int y){
	mark[x][y] = 1;
	for(int i = 0; i < 8; i++){ // All 8 directions
		int nx = x + gx[i];
		int ny = y + gy[i];
		if(validate(nx,ny)){
			if(arr[nx][ny] && !mark[nx][ny])
				dfs(nx,ny);
		}
	}
}

int main(){
	int t; cin >> t;
	FOR(k,1,t){
		memset(arr,0,sizeof(arr));
		memset(mark,0,sizeof(mark));
		ll n; cin >> n;
		FOR(i,1,n){
			ll x,y; cin >> x >> y;
			arr[x][y] = 1;
		}
		ll ans = dfs_visit();
		cout << "Case " << k << ": " << ans << '\n';		
	}		
}