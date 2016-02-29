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

int dp[2005][2005]; // Transform string of length i to string of length j

int main(){
	int t; cin>> t;
	while(t--){
		string a,b;
		cin >> a >> b;
		a = " " + a;
		b = " " + b;

		int m = a.length();
		int n = b.length();

		FOR(i,0,m)
			FOR(j,0,n)
				dp[i][j] = INT_MAX;

		FOR(i,0,m)
			dp[i][0] = i; // i operations required to make them equal
		FOR(i,0,n)
			dp[0][i] = i;

		FOR(i,1,m){
			FOR(j,1,n){
				if(a[i] == b[j])
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				else
					dp[i][j] = min(dp[i][j], 1 + dp[i-1][j-1]); // Replace
				dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]); // Delete from i
				dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]); // Insert into j
			}
		}

		cout << dp[m][n] << '\n';
	}	
}

/*
int editDistance(string a, string b, int al, int bl){
	if(al < 0 && bl < 0)
		return 0;
	else if(al < 0)
		return bl + 1; // Delete the bl elements left
	else if(bl < 0)
		return al + 1; // Delete the al elements left

	if(dp[al][bl] != -1)
		return dp[al][bl];

	int ans = INT_MAX;

	if(a[al] == b[bl])
		ans = min(ans, editDistance(a,b,al-1,bl-1));
	else
		ans = min(ans, 1 + editDistance(a,b,al-1,bl-1)); // Replace last character

	ans = min(ans, 1 + editDistance(a,b,al-1,bl)); // Transform first al-1 char into bl by removing one from 'a'
	ans = min(ans, 1 + editDistance(a,b,al,bl-1)); // Transform al char into bl-1 and insert into 'b' later
	
	dp[al][bl] = ans;
	return dp[al][bl];
}
*/