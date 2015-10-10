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
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll more = max(n,m);
		ll less = min(n,m);
		ll a,b;
		ll a2,b2;
		a2 = a = less - 1;
		b2 = b = less;
		ll leftover = more - less;

		if(less%2){
			a += (leftover - 1);
			b++;

			a2 += leftover;
		}
		else{
			a += leftover;

			a2 += (leftover - 1);
			b2++;
		}

		if(a > b || a2 > b2)
			cout<<"Player A wins\n";
		else
			cout<<"Player B wins\n";
	}	
}