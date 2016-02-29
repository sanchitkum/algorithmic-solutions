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
	ll t; cin >> t;
	FOR(k,1,t){
		ll n; cin >> n;
		vector<ll> v(n+1);
		FOR(i,1,n)
			cin >> v[i];
		ll dpYes[n+1];
		ll dpNo[n+1];

		dpYes[0] = 0; // Maximum I can get by taking this coin
		dpNo[0] = 0; // Maximum I can get without taking this coin

		FOR(i,1,n){
			dpYes[i] = dpNo[i-1] + v[i];
			dpNo[i] = max(dpYes[i-1],dpNo[i-1]);
		}
		cout << "Case " << k << ": " << max(dpYes[n],dpNo[n]) << '\n';
	}	
}