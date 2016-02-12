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
#define MAXN 1000000

vector<ll> v;
vector<ll> factorialLength(MAXN+1,0);
int n;
ll ans = 0;

bool mark_prime[MAXN+1];
// vector<ll> primes;

void sieve(){
	memset(mark_prime,1,sizeof(mark_prime));
	for(ll i = 2; i <= MAXN; i++){
		if(mark_prime[i]){
			// primes.pb(i); // i'th element is the prime element
			factorialLength[j] = 1; // Prime number
			for(ll j = i+i; j <= MAXN; j += i){
				mark_prime[j] = 0; // Mark non primes
				ll k = j;
				while(k % i == 0){ // Add the particular prime to powers
					factorialLength[j]++;
					k /= i;
				}
			}
		}
	}
} 

void possibleSubsets(){
	ll total = 1 << n;
	for(ll i = 1; i < total; i++){
		ll factorialSum = 0;
		for(ll j = 0; j < n; j++){
			if( i & (1 << j))
				factorialSum += factorialLength[ v[j] ];
		}
		// debug(factorialSum);
		if(factorialSum % 2 == 0) // even
			ans += factorialSum;
	}
}

int main(){
	sieve(); // Precompute prime factorials

	// Update since in factorials, powers will get added
	for(ll i = 3; i <= MAXN; i++){
		factorialLength[i] += factorialLength[i-1];
	}

	// Input
	cin >> n;
	for(int i = 0; i < n; i++) {
		ll x; cin >> x;
		v.pb(x);
	}

	// Find subsets and sum
	possibleSubsets();
	cout << ans << '\n';
}