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
We want to have all buildings at the same height.
Suppose the answer H. Some buildings may be taller and others smaller. The optimal cost would be .
The key is to realize that this sum as a function of H is an unimodal function.
It grows more and more as we move H further away from the optimal value either to the left (smaller values) or to the right (higher values).
Suppose the answer is unique at H = 10, then the cost(H = 9) > cost(H = 10) < cost(H = 11).
Hence, we can use Ternary search on the answer. We know that the heights are between 0 and 10 000.

Link: https://en.wikipedia.org/wiki/Ternary_search

Let a unimodal function f(x) on some interval [l; r]. Take any two points m1 and m2 in this segment: l < m1 < m2 < r.
Then there are three possibilities:

    1. 	if f(m1) < f(m2), then the required maximum can not be located on the left side - [l; m1].
    	It means that the maximum further makes sense to look only in the interval (m1;r]
    2. 	if f(m1) > f(m2), that the situation is similar to the previous, up to symmetry.
    	Now, the required maximum can not be in the right side - [m2; r], so go to the segment [l; m2]
    3. 	if f(m1) = f(m2), then the search should be conducted in [m1; m2],but this case can be attributed to any of the previous two
    	(in order to simplify the code). Sooner or later the length of the segment will be a little less than a predetermined constant,
    	and the process can be stopped.

*/

vector< pair<ll,ll> > hc;

ll F(ll h){ // return the cost of converting all building to this height
	ll cost = 0;
	for(ll i = 0; i < hc.size(); i++){
		cost += ( abs(h - hc[i].first) * hc[i].second );
	}
	return cost;
}

int main(){
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		hc.clear();
		hc.resize(n);

		ll min_height = INT_MAX;
		ll max_height = INT_MIN;

		for(ll i = 0; i < n; i++){
			cin >> hc[i].first; // Height
			min_height = min(min_height,hc[i].first);
			max_height = max(max_height,hc[i].first);
		}
		for(ll i = 0; i < n; i++)
			cin >> hc[i].second;

		sort(all(hc));
		ll left = min_height;
		ll right = max_height;
		while(true){
			// debug(left); debug(right);
			if(abs(right - left) <= 2) // To avoid infinite loop in case of while(left < right)
				break;
			ll leftThird = left + (right - left) / 3;
			ll rightThird = right - (right - left) / 3;
			if(F(leftThird) > F(rightThird))
				left = leftThird;
			else
				right = rightThird;
		}
		ll min_ans = min( F(left), min( F(left+1), F(right) ) );
		cout << min_ans << '\n';
	}	
}