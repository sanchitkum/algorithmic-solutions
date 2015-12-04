#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl 
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
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

		sort(all(v));
		
		int res = 0;
		FOR(j,0,n-1){
			int ans = 1;
			int sum = v[j]; // include this particular position
			int pos = j;
			FOR(i,0,n-1){
				int	idx = lower_bound(v.begin()+(j+1),v.end(),sum) - v.begin();
				if(idx == n)
					break;
				sum += v[idx];
				pos = idx;
				ans++;
			}
			res = max(res,ans);
		}
		cout << res << '\n';
	}
}