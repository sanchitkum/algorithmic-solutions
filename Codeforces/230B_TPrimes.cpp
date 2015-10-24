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

ll n = 1000000;
vector<bool> mark(n+1,0);
set<ll> Tprime;

void sieve(){
	for(ll i = 2; i <= n; i++){
		if(!mark[i]){
			Tprime.insert(i*i);
			for(ll j = i*i; j <= n; j += i){
				mark[j] = 1;
			}
		}
	}
}

int main(){
	sieve();
	ll q; cin >> q;
	while(q--){
		ll x; cin >> x;
		if(Tprime.count(x))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}