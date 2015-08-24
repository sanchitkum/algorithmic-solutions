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
	ll a,b,val;
	ll k,m;
	cin>>a>>b>>k>>m;
	vector<ll> v1,v2;
	FOR(i,0,a-1)
	{
		cin>>val;
		v1.pb(val);
	}
	FOR(i,0,b-1)
	{
		cin>>val;
		v2.pb(val);
	}
	if (v1[k-1] < v2[b-m])
		cout<<"YES";
	else
		cout<<"NO";

};