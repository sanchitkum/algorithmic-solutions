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
	int t; cin >> t;
	while(t--){
		ll a,b,c; cin >> a >> b >> c;

		if(c > max(a,b) || c % __gcd(a,b) != 0){ // Not needed
			cout << "-1\n";
		}
		else{
			map< pair<ll,ll>, bool > dp;
			set< pair<ll, pair<ll,ll> > > s;
			s.insert(mp(0,mp(0,0)));

			ll ans = -1;

			while(!s.empty()){
				ll x = s.begin()->S.F;
				ll y = s.begin()->S.S;
				ll step = s.begin()->F;
				s.erase(s.begin());

				if(x == c || y == c){
					ans = step; break;
				}

				if(dp[mp(x,y)])
					continue;
				else
					dp[mp(x,y)] = true;

				if(x == 0) // If x is empty, make it full
					s.insert( mp(step+1, mp(a,y) ) );
				else if(x == a) // If x is full, make it empty
					s.insert( mp(step+1, mp(0,y) ) );

				if(y == 0) // If y is empty, make it full
					s.insert( mp(step+1, mp(x,b) ) );
				else if(y == b) // If x is full, make it empty
					s.insert( mp(step+1, mp(x,0) ) );

				// Transfer from x to y
				ll nx = x - min(x,(b-y));
				ll ny = y + min(x,(b-y));
				s.insert( mp(step+1, mp(nx,ny) ) );

				// Tansfer from y to x
				nx = x + min(y,(a-x));
				ny = y - min(y,(a-x));
				s.insert( mp(step+1, mp(nx,ny) ) );
			}
			cout << ans << '\n';
		} 
	}
}