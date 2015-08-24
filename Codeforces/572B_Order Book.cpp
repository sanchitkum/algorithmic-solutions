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

ll sell[100005] = {0};
ll buy[100005] = {0};


int main()
{
	ll n,s;
	cin>>n>>s;
	FOR(i,0,n-1)
	{
		char ch; ll p,q;
		cin>>ch>>p>>q;
		if (ch == 'S')
			sell[p] += q;
		else if (ch == 'B')
			buy[p] += q;
	}
	ll a = 0;
	
	bool mark[100004] = {0};

	FOR(i,0,100004)
	{
		if(sell[i] > 0)
		{
			mark[i] = 1;
			a++;
		}
		if(a >= s)
			break;
	}

	a = 0;
	
	ROF(i,100004,0)
	{
		if(mark[i] > 0)
		{
			cout<<'S'<<" "<<i<<" "<<sell[i]<<'\n';
			a++;
		}
		if(a >= s)
			break;
	}

	a = 0;
	ROF(i,100004,0)
	{
		if(buy[i] > 0)
		{
			cout<<'B'<<" "<<i<<" "<<buy[i]<<'\n';
			a++;
		}
		if(a >= s)
			break;
	}
}