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

ll sum[26] = {0}; // Maintained in 1 based index
ll dp[26][9*26] = {-1};
ll N;

ll rec(ll r, ll val){
	if(dp[r][val] != -1)
		return dp[r][val];

	ll ans = 0;

	for(ll i = r+1; i <= N-1; i++){
		if( (sum[i] - sum[r] <= sum[N] - sum[i]) && (sum[i] - sum[r] >= val) )
			ans += 1 + rec( i, sum[i] - sum[r] );
	}

	dp[r][val] = ans;
	return dp[r][val];
}

int main(){
	ll k = 1;
	while(true){
		string s; cin >> s;
		if(s == "bye")
			break;
		memset(sum,0,sizeof(sum));
		memset(dp,-1,sizeof(dp));

		N = s.length();
		for(int i = 0; i < s.length(); i++){
			sum[i+1] = sum[i] + (s[i] - '0');
		}

		ll ans = rec(0,0) + 1; // +1 for the whole set, Eg. [1117]
		cout << k++ << ". " << ans << '\n';
	}
}