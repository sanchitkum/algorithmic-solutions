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

vector<double> v;
double dp[1005][1005];
bool mark[1005][1005];

double rec(ll x, ll k)
{
	if(x >= (ll)v.size())
		if( k != 0 )
			return 0.0;
		else
			return 1.0;
	if(mark[x][k])
		return dp[x][k];
	mark[x][k] = 1;
	double val = 0;
	if(k)
		val += rec(x+1,k-1)*v[x];
	val += rec(x+1,k)*(1-v[x]);
	return dp[x][k] = val;
}

int main()
{
	ll t,n,k;
	cin>>t;
	FOR(yy,1,t)
	{
		memset(mark,0,sizeof mark);
		cin>>n>>k;
		v.clear();
		double val;
		FOR(i,1,n)
		{
			cin>>val;
			v.pb(val);
		}
		cout<<"Case "<<yy<<": ";
		printf("%0.2lf\n",rec(0,k));
	}
}
