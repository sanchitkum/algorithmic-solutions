#include <bits/stdc++.h>
typedef long long ll;
// #define get(a) scanf("%lld", &a)
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define F first
#define S second
#define mp make_pair
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v;
		FOR(i,1,n){
			int x; cin >> x;
			v.pb(x);
		}

		vector<int> ans;
		ans.insert(ans.begin(),1);
		int res = 0;
		FOR(i,1,n-1){
			if(v[i] == 0){
				ans.insert(ans.begin(),i+1);
				continue;
			}
			auto itx = find(ans.begin(),ans.end(),v[i]);
			int idx = itx - ans.begin() + 1;
			int s = ans.size();
			res += min(idx,s-idx);
			ans.insert(itx+1,i+1);
		}
		// FOR(i,0,n-1){
			// debug(ans[i]);
		// }
		cout << res <<'\n';
	}
}