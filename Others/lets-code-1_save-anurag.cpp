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

#define MAX 10000000
set<ll> prime_square;
vector<ll> mark(MAX+1,1);

void sieve(){
	for(ll i = 2; i <= MAX; i++){
		if(mark[i]){
			prime_square.insert(i);
			prime_square.insert(i*i);
			mark[i] = 0;
			for(ll j = i*i; j <= MAX; j += i)
				mark[j] = 0; 
		}
	}
}

int main(){
	ll n; cin >> n;
	prime_square.insert(1);
	sieve();
	FOR(i,1,n){
		ll x; cin >> x;
		if(prime_square.count(x) == 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}	
}