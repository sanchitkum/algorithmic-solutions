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
		ll n,k;
		cin>>n>>k;
		vector<string> v;
		string str;
		FOR(i,1,n){
			cin>>str;
			v.pb(str);
		}
		set<string> ss;
		FOR(i,1,k){
			ll m; cin>>m;
			FOR(j,1,m){
				cin>>str;
				ss.insert(str);
			}
		}
		for(auto q: v){
			if(ss.count(q))
				cout<<"YES ";
			else 
				cout<<"NO ";
		}
		cout<<'\n';
	}
}