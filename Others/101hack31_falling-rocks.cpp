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
vector<string> v;
bool mark[1005][1005] = {0};
bool possible;

void BFS(int xx, int yy){
	queue< pair<int, int> > q;
	q.push(mp(xx,yy));
	pair<int,int> pval;

	while(!q.empty()){
		pval = q.front();
		q.pop();

		if(pval.F == m-1){ // Reached the end
			possible = true;
			break;
		}

		int x = pval.F;
		int y = pval.S;

		if( x+1 <= m-1 ){
			// Go left
			if( y - 1 >= 0 ){
				if(v[x][y-1] != 'R' && v[x+1][y-1] != 'R'){
					if(!mark[x+1][y-1]){
						mark[x+1][y-1] = 1;
						q.push(mp(x+1,y-1));
					}
				}
			}

			// Stay there
			if(v[x+1][y] != 'R'){
				if(!mark[x+1][y]){
					mark[x+1][y] = 1;
					q.push(mp(x+1,y));
				}
			}

			// Go Right
			if( y + 1 < n ){
				if(v[x][y+1] != 'R' && v[x+1][y+1] != 'R'){
					if(!mark[x+1][y+1]){
						mark[x+1][y+1] = 1;
						q.push(mp(x+1,y+1));
					}
				}
			}
			
		}
	}
}

int main(){
	cin >> n >> m;
	FOR(i,0,m-1){
		string s; cin >> s;
		v.pb(s);
	}

	possible = false;
	FOR(i,0,n-1){
		if(v[0][i] == 'Y')
			{ BFS(0,i); break; }
	}

	if(possible)
		cout << "YES";
	else
		cout << "NO";
}