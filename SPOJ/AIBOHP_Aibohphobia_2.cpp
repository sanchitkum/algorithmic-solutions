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
Logic: length = length of string - lengthof (LCS of string and its reverse)
*/

ll dp[6105][6105];

int main(){
	ll t; cin >> t;
	while(t--){
		string s; cin >> s;
		string r = s;
		reverse(all(r));
		
		s = " " + s;
		r = " " + r;

		FOR(i,0,s.length())
			FOR(j,0,r.length())
				dp[i][j] = INT_MIN;

		FOR(i,0,s.length())
			dp[i][0] = 0;
		FOR(i,0,r.length())
			dp[0][i] = 0;

		FOR(i,1,s.length()){
			FOR(j,1,r.length()){
				if(s[i] == r[j])
					dp[i][j] = max(dp[i][j],1 + dp[i-1][j-1]);
				dp[i][j] = max(dp[i][j],dp[i-1][j]); 
				dp[i][j] = max(dp[i][j],dp[i][j-1]);
			}
		}

		ll lcs = dp[s.length()][r.length()];
		ll ans = s.length() - lcs;
		cout << ans << '\n';
	}	
}