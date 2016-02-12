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

/*
Tutorial: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/
Link: https://www.quora.com/What-is-the-correct-approach-to-solve-the-SPOJ-problem-Aggressive-cow

For the problem at hand, let us define the following function:
F(x) = 1 if it is possible to arrange the cows in stalls such that the distance between any two cows is at least x
F(x) = 0 otherwise

Now it is easy to see that IF F(x)=0, F(y)=0 for all y>x.
Thus, the problem satisfies the monotonicity condition necessary for binary search.
It is also easy to find two values of x which give F(x)=0 and 1 respectively.
F(0)=1 trivially since the distance between any two cows is at least 0.
Also, since we have at least two cows,
the best we can do is push them towards the stalls at the end - so there is no way we can achieve better.
Hence F(maxbarnpos-minbarnpos+1)=0.

Now, how do we check whether F(x)=1 for a general value of x?
We can do this with a greedy algorithm: Keep placing cows at the leftmost possible stalls
such that they are at least x distance away from the last placed cow.
*/

vector<ll> v;

bool F(ll distance, ll cows){
	ll lastpostion = v[0];
	ll count = 1;
	for(ll i = 1; i < v.size(); i++){
		if(v[i] - lastpostion >= distance){ // Minimum distance achieved
			count++; // Assign a new cow here
			if(count == cows)
				return true; // We were able to assign all cows with this distance
			lastpostion = v[i];
		}
	}
	return false;
}

int main(){
	ll t; cin >> t;
	while(t--){
		ll n,c; cin >> n >> c;
		v.clear();
		for(ll i = 0; i < n; i++){
			ll x; cin >> x;
			v.pb(x);
		}
		sort(all(v));
		ll low = INT_MAX;
		for(ll i = 0; i <= n-2; i++)
			low = min(low,v[i+1]-v[i]);
		ll high = v[n-1] - v[0] + 1;
		while(low < high){
			ll x = low + (high - low + 1)/2;
			// ll x = (low + high) / 2;
			// debug(x); debug(low); debug(high);
			if(F(x,c)) // can we accomodate the cows at a distance of 'x' from each other
				low = x; // yes, so we need this or greater estimate 
			else // we could not accomodate the cows with 'x' distance
				high = x - 1; // no, so we need a lower estimate
		}
		cout << high << '\n';
	}	
}