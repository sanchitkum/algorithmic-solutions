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

int main()
{
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll val;
		vector< pair<ll,pair<ll,ll> > > s; 
		FOR(i,1,n){
			FOR(j,1,n){
				cin>>val;
				s.pb( mp( val, mp(i,j) ) );
			}
		}
		sort(all(s));
		ll sum = 0;
		FOR(i,1,(n*n)-1){
			sum += ( abs(s[i].S.S - s[i-1].S.S) +  abs(s[i].S.F - s[i-1].S.F) );
		}
		cout<<sum<<'\n';
	}
}