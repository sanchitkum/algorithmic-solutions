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

#define N 9000

vector<ll> mark(N+1,1);
vector<ll> ans(2*N,0); // Initially none is answer;
vector<ll> prime;

void sieve(){
	for(ll i = 2; i <= N; i++){
		if(mark[i]){
			prime.pb(i);
			for(ll j = i*i; j <= N; j += i)
				mark[j] = 0;
		}
	}
}

int main(){
	sieve();
	FOR(i,0,prime.size()-1) { // From 1 prime
		ans[ prime[i] ] = 1;
	}

	FOR(i,0,prime.size()-1){ // From 2 prime
		FOR(j,i,prime.size()-1){
			ans[ prime[i] | prime[j] ] = 1;
		}
	}
	FOR(i,1,N){ // From 3 prime
		if(ans[i]){
			FOR(j,0,prime.size()-1){
				ans[ i | prime[j] ] = 1;
			}
		}
	}
	FOR(i,1,N){ // From 4 prime
		if(ans[i]){
			FOR(j,0,prime.size()-1){
				ans[ i | prime[j] ] = 1;
			}
		}
	}

	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;		
		if(ans[n])
			cout << "YES";
		else
			cout << "NO";
        cout << '\n';
	}
}