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
	ll t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		ll cnt = 0;
		FOR(i,0,s.length()-1)
			cnt += s[i] - 'a';
		if(cnt%2 == 0)
			cout<<"Bob\n";
		else
			cout<<"Alice\n";
	}
}