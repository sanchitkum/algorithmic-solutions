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
		int f,h,w; cin >> f >> h >> w;
		vector<int> p;
		FOR(i,1,f){
			int x; cin >> x;
			p.pb(x);
		}
		sort(all(p));
		vector<ll> area;
		area.pb(p[0]*h);
		FOR(i,1,p.size()-1){
			ll wid = p[i]-p[i-1];
			area.pb(wid*h);
		}
		ll wid = w-p[p.size()-1];
		area.pb(wid*h);
		sort(all(area));
		cout << area[0] << '\n';
	}	
}