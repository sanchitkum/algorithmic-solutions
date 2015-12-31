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
	//BOOST;
	while(true){
		ll n,k; cin >> n >> k;
		if(n == -1 && k == -1)
			break;
		assert(n >= 2); // Since we need to pick atleast two balls
		ll min_sum = 1 + 2;
		ll max_sum = n + (n-1);
		if(k < min_sum)
			cout << "0\n";
		else if(k > max_sum)
			cout << "1\n";
		else{
			ll q = (n*(n-1)) / 2; // nC2
			ll p;
			if(k%2){ // odd
				ll m = k/2;
				p = m*m; 
			}
			else{ // even
				ll m = (k/2)-1;
				p = (m*m) + m;
			}
			while( __gcd(p,q) != 1 ){
				ll divisor = __gcd(p,q);
				p /= divisor;
				q /= divisor;
			}
			cout << p << "/" << q << '\n';
		}
	}
}