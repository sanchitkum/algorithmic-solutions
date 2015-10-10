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
#define MAX 1000000000000000000

vector<ll> v;

ll fast_pow(ll base, ll exp){
	ll res = 1;
	while(exp > 0){
		if(exp % 2 ==  1) res *= base;
		base *= base;
		exp >>= 1; 
	}
	return res;
}

void precompute(){
	v.pb(1);
	FOR(i,1,60){
		FOR(j,0,38){
			ll val = fast_pow(2,i) * fast_pow(3,j);
			if(val <= MAX && val > 0)
				v.pb(val);
			else
				break;
		}
	}
}

int main(){
	ll t; cin>>t;
	precompute();
	sort(all(v));
	//debug(v.size());
	while(t--){
		ll l,r; cin>>l>>r;
		ll start = lower_bound(all(v),l) - v.begin();
		ll end = upper_bound(all(v),r) - v.begin();
		cout<<end-start<<'\n';
	}
}