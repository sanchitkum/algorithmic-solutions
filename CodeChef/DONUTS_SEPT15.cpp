#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( typeof((v).begin()) it = v.begin(); it != v.end(); it++ )
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
		ll n,m,val;
		get(n); get(m);
		vector<ll> v;
		FOR(i,1,m){
			get(val);
			v.pb(val);
		}
		sort(all(v));
		ll ans = 0;
		FOR(i,0,v.size()-1){
			if(m <= 1)
				break;
			if(v[i] == 1)
				{ m -= 2; ans++; }
			else{
				while(v[i] > 0){
					if(v[i] == 1)
						m -= 2;
					else
						m -= 1;
					v[i]--;
					ans++;
					if(m <= 1)
						break;
				}
			}
		}
		printf("%lld\n",ans);
	}	
} 