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


// Explanation to problem: https://www.quora.com/Can-somebody-explain-solution-to-SPOJ-com-Problem-M3TILE

int main(){
	int dp[31];

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;

	for(int i = 4; i < 31; i++)
		dp[i] = 4*dp[i-2] - dp[i-4];

	while(true){
		int n; cin >> n;
		if(n == -1)
			break;
		cout << dp[n] << '\n';
	}	
}