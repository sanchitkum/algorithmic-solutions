#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<ll> merge(vector<ll> a, vector<ll> b){
	int i = 0;
	int j = 0;
	vector<ll> ans;
	while(i < a.size() && j < b.size()){
		if(a[i] >= b[j])
			ans.pb(a[i++]);
		else
			ans.pb(b[j++]);
	}
	while(i < a.size()){
		ans.pb(a[i++]);
	}

	while(j < b.size()){
		ans.pb(b[j++]);
	}
	return ans;
}

int main() {
	int t; cin >> t;
	while(t--){
		int  n,m; cin >> n >> m;
		vector<ll> a,b;
		FOR(i,1,n){
			ll x; cin >> x;
			a.pb(x);
		}
		FOR(i,1,m){
			ll x; cin >> x;
			b.pb(x);
		}
		vector<ll> ans = merge(a,b);
		FOR(i,0,ans.size()-1)
			cout << ans[i] << " ";
		cout << '\n';
	}
}