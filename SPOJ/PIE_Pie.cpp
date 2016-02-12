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

const double PI = 3.14159265358979323846264338327950;
vector<double> v;

bool F(double x, ll friends){
	ll count = 0;
	vector<double> pie = v;
	for(ll i = 0; i < pie.size(); i++){
		if(pie[i] >= x){
			pie[i] -= x; // Subtract 'x' as it has been consumed
			count++; // A pie has been alloted
			if(count == friends) // We achieved this 'x' volume for all friends
				return true;
			i--; // To again check from available pie from this position
		}
	}
	return false;
}

int main(){
	ll t; cin >> t;
	while(t--){
		ll n,f; cin >> n >> f;
		v.clear();
		for(ll i = 0; i < n; i++){
			ll r; cin >> r;
			v.pb(PI*r*r); // Volume of each Pie
		}
		sort(all(v));

		double low = 0;
		double high = *max_element(all(v));

		for(int i = 0; i < 100; i++){ // 100 iterations are enough for precision. Since Double we cant do while(low < high)
			double x = (low + high) / 2;
			if(F(x,f+1)) // Can we achieve 'x' volume for all friends
				low = x;  // yes, try for a higher estimate
			else
				high = x; // no, try for a lower estimate
		}
		printf("%.4f\n",low);
	}	
}