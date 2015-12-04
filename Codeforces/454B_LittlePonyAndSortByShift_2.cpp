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

int main(){
	ll n; cin >> n;
	vector<ll> v(n);
	
	FOR(i,0,n-1)
		cin >> v[i];

	int d_flag = 0; // decrement flag
	int d_idx;
	FOR(i,1,n-1){
		if(v[i] < v[i-1]){
			d_flag = 1;
			d_idx = i;
			break;
		}
	}

	if(d_flag == 0)
		{ cout << "0"; return 0; }

	int p_flag = 1; // Possible flag;
	FOR(i,d_idx+1,n-1){
		if(v[i] < v[i-1]){
			p_flag = 0;
			break;
		}
	}

	if(p_flag == 0 || v[n-1] > v[0])
		cout << "-1";
	else
		cout << n-d_idx;
}