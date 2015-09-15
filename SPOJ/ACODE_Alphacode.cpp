#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%ld", &a)
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
	string s;
	while(true)
	{
		cin>>s;
		if(s[0] == '0')
			break;
		ll dp[5005] = {0};
		dp[0] = 1;
		FOR(i,1,s.length()-1)
		{
			//debug(i);
			//debug(s[i]);
			dp[i] = dp[i-1];
			if(s[i] == '0')
				dp[i] -= dp[i-1];
			if(i == 1)
			{
				if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
					dp[i] += 1;
			}
			else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
				dp[i] += dp[i-2];
			//debug(dp[i]);
		}
		cout<<dp[s.length()-1]<<'\n';
	}	
}