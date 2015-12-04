#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
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
		int ans = 2;
		if(n == 1)
			ans = 1;
		else if(n == 2)
			ans = 2;
		else{
			int cnt = 2; // Guranteed to be 2
			FOR(i,2,n-1){
				if(v[i] == v[i-1] + v[i-2]){
					cnt++;
					ans = max(ans,cnt);
				}
				else
					cnt = 2;
			}
		}
		cout << ans << '\n';
	}	
}