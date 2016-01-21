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

vector<string> arr;
ll n;

int gx[] = {-1,0,1,0};
int gy[] = {0,-1,0,1};
int mark[1001][1001] = {0};

bool reachable_bfs(){
	queue< pair<int,int> > q;
	q.push(mp(0,0)); // Starting point
	mark[0][0] = 1;
	pair<int,int> pval,temp;
	while(!q.empty()){
		pval = q.front();
		q.pop();
		// mark[pval.F][pval.S] = 1;
		for(int i = 0; i < 4; i++){
			int x = pval.F + gx[i];
			int y = pval.S + gy[i];
			if(x >= 0 && x < n && y >= 0 && y < n){
				if(!mark[x][y] && arr[x][y] == '.'){
					q.push(mp(x,y));
					mark[x][y] = 1;
				}
			}
		}
		if(mark[n-1][n-1])
			return true;
	}
	return false;
}

int main(){
	BOOST;
	cin >> n;
	FOR(i,1,n){
		string s; cin >> s;
		arr.pb(s);
	}

	ll mod = (1LL << 31LL) - 1;
	// debug(mod);
	ll path[n][n];
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			path[i][j] = 0;
		}
	}
	path[0][0] = 1; // Starting point

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			if(i+1 < n && arr[i+1][j] == '.')
				path[i+1][j] = (path[i+1][j] + path[i][j]) % mod;
			if(j+1 < n && arr[i][j+1] == '.')
				path[i][j+1] = (path[i][j+1] + path[i][j]) % mod;
		}
	}

	if(path[n-1][n-1])
		cout << path[n-1][n-1] % mod << '\n';
	else if(reachable_bfs())
		cout << "THE GAME IS A LIE\n";
	else
		cout << "INCONCEIVABLE\n";
	return 0;
}

/*
// TLE
// Initialize the first row and first column; Not reachble means -1
for(ll i = 1; i < n; i++){ 
	if(arr[i][0] != '#') // If it is reachable then 
		path[i][0] = path[i-1][0];	// The count from previous cell
	else
		path[i][0] = -1; // Not reachable

	if(arr[0][i] != '#') 
		path[0][i] = path[0][i-1];
	else
		path[0][i] = -1;
}

for(ll k = 0; k < 2*n-1; k++){ // Reverse Diagonals
	for(ll i = 1; i < n; i++){
		for(ll j = 1; j < n; j++){
			if(i+j == k){ // Indices of elements in reverse diagonal is constant
				if(arr[i][j] != '#'){
					if(path[i-1][j] != -1 && path[i][j-1] != -1)
						path[i][j] = (path[i-1][j] + path[i][j-1]) % mod;
					else if(path[i-1][j] == -1)
						path[i][j] = path[i][j-1];
					else
						path[i][j] = path[i-1][j]; 
				}
				else
					path[i][j] = -1;
			}
		}
	}
}
*/