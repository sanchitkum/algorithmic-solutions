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

int mark[1001][1001];
int arr[1001][1001];
int d[1001][1001];
int n;

int gx[] = {1,0,-1,0};
int gy[] = {0,1,0,-1};

int bfs(int x, int y){
	mark[x][y] = 1;
	d[x][y] = 0;
	queue< pair<int,int> > q;
	q.push(mp(x,y));
	pair<int,int> pval;
	while(!q.empty()){
		pval = q.front();
		q.pop();
		for(int i=0; i < 4; i++){
			int nx = pval.F + gx[i];
			int ny = pval.S + gy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n){
				if(!mark[nx][ny]){
					mark[nx][ny] = 1;
					d[nx][ny] = d[pval.F][pval.S] + 1;
					if(arr[nx][ny] == 3)
						return d[nx][ny];
					q.push(mp(nx,ny));
				}
			}
		}
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		vector< pair<int,int> > v;
		FOR(i,0,n-1){
			FOR(j,0,n-1){
				cin >> arr[i][j];
				if(arr[i][j] == 1){
					v.pb(mp(i,j));
				}
			}
		}	

		int max_ans = INT_MIN;
		for(int i = 0; i < v.size(); i++){
			memset(mark,0,sizeof(mark));
			memset(d,0,sizeof(d));
			int ans = bfs(v[i].F,v[i].S);
			max_ans = max(max_ans,ans);
		}
		cout << max_ans << '\n';
	}
}