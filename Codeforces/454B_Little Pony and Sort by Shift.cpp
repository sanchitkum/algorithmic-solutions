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
	ll n,val;
	cin>>n;
	vector<ll> v;
	FOR(i,1,n)
	{
		cin>>val;
		v.pb(val);
	}
	int flag = 0;
	ll i = 0;
	do
	{
		if(v[i] > v[i+1])
			{flag = 1; break;}
		i++;
	}while(i <= n-2);

	if(!flag)
		{ cout<<"0"; return 0; }

	if(n==2)
		if(v[0] < v[1])
			{ cout<<"0"; return 0; }
		else
			{ cout<<"1"; return 0; }			

	flag = 0;
	i = 0;
	ll first = v[0];
	ll cnt = 0;

	while( i <= n-2 && v[i] <= v[i+1])
		{ i++; continue; }
	i++;

	for(;i<=n-1;i++)
	{
		//debug(i);
		if(i<= n-2)
		{
			//debug(v[i]);
			if(v[i] > v[i+1] || v[i] > first)
				{ flag = 1; break; }
			else
				cnt++;
		}
		else
			cnt++;
	}

	if(v[n-1] > first)
		flag = 1;

	if (flag)
		cout<<"-1";
	else
		cout<<cnt;

}