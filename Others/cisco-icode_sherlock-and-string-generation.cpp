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
	ll t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll lower = ( (k/2)*2 ) + ceil(1.0*k/2);
		//debug(lower);
		if(lower > n || (n-lower)%2 )
			{ cout<<"No such string.\n"; continue; }
		ll extra = n-lower;
		//debug(extra);
		FOR(i,'a','a'+k-1)
		{
			while(extra > 0)
				{ cout<<'a'; extra--; }
			if(i%2)
				cout<<(char)i;
			else
				cout<<(char)i<<(char)i;
		}
		cout<<'\n';
	}
}
