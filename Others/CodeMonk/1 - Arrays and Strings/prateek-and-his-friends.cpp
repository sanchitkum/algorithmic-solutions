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

int main(){
	int t; cin >> t;
	while(t--){
		ll n, x; cin >> n >> x;
		vector<ll> v;
		for(ll i = 0; i < n; i++) {
			ll z; cin >> z;
			v.pb(z);
		}
		ll sum = 0; // contiguous sum
		ll j = 0; // index to begin at 0
		int flag = 0;
		for(ll i = 0; i < n; i++){
			sum += v[i];
			while(sum > x)
				sum -= v[j++];
			if(sum == x)
				{flag = 1; break;}
		}
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
}