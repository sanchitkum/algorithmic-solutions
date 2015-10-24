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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> prime;
vector<bool> mark(100001,1);

void sieve(){
	for(ll i = 2; i <= 100000; i++){
		if(mark[i]){
			prime.pb(i);
			for(ll j = i*i; j <= 100000; j += i){
				mark[j] = 0;
			}
		}
	}
}

int main(){
	sieve();
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> v;
		ll primesize = lower_bound(all(prime),n) - prime.begin();
		if(prime[primesize] > n)
			primesize--;
		v.pb(0);
		FOR(i,1,n){
			ll x; cin >> x;
			v.pb(x);
		}
		ll maxsum = 0;
		for(ll i = 0; i <= primesize; i++){
			ll prime_value = prime[i];
			ll sum = 0;
			for(ll j = prime_value; j <= n; j += prime_value){
				sum += v[j];
			}
			maxsum = max(maxsum,sum);
		}
		cout << maxsum << '\n';
	}
}