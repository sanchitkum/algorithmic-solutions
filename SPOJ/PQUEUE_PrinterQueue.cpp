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
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		queue< pair<int,int> > q;
		vector<int> count_priority(10,0); // From 0 to 9
		FOR(i,0,n-1){
			int x; cin >> x;
			q.push(mp(x,i));
			count_priority[x]++;
		}
		pair<int,int> pval;
		int ans = 0;
		while(!q.empty()){
			pval = q.front();
			int flag_repush = 0;
			for(int i = pval.F+1; i <= 9; i++){
				if(count_priority[i]){
					flag_repush = 1;
					break;
				}
			}
			if(flag_repush){ // Again push it to the back;
				q.pop();
				q.push(pval);
			}
			else{
				q.pop();
				ans++; // Printing done
				count_priority[pval.F]--;
				if(pval.S == m)
					break;
			}
		}
		cout << ans << '\n';
	}	
}