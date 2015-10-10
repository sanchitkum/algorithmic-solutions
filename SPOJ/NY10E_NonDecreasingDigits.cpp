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

ll n;
ll dp[65][10];

ll rec(ll digit, ll last){
	ll sum = 0;
	if(digit > n)
		return 1;
	if(dp[digit][last] != -1)
		return dp[digit][last];
	FOR(i,last,9){
		//printf("Rec[%lld][%lld] = %lld and last = %lld\n",digit,i,sum,last);
		sum += rec(digit+1,i);
	}
	//printf("After ALL Rec[%lld][%lld] = %lld\n",digit,last,sum);
	return dp[digit][last] = sum;
}

int main(){
	ll t; cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		ll x; cin>>x>>n;
		cout<<x<<" "<<rec(1,0)<<'\n';
	}	
}