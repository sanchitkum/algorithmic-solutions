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
using namespace std;

bool compare(pair<ll,ll> a, pair<ll,ll> b){
	if(a.F != b.F)
		return a.F < b.F; // Normal compare logic when different
	else
		return a.S > b.S; // Special case when same, then choose smaller one!
}

int main(){
	ll n,k; cin >> n >> k;
	vector<ll> a(n+1),b(n+1);
	FOR(i,1,n)
		cin >> a[i];
	FOR(i,1,n)
		cin >> b[i];

	priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, decltype(&compare)> prod(&compare);

	FOR(i,1,n)
		prod.push(mp(a[i]*b[i],i));

	while(k--){
		pair<ll,ll> temp;
		temp = prod.top();
		if(a[temp.S] > 0){
			prod.pop();
			a[temp.S]--;
			prod.push(mp(a[temp.S]*b[temp.S],temp.S));
		}
	}

	FOR(i,1,n)
		cout << a[i] << " ";
}