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
	vector<ll> vc;
	vc.pb(0);
	ll sum = 0;
	FOR(i,1,n)
	{
		cin>>val;
		sum += val;
		vc.pb(sum);
	}
	ll ans = 0;
	if(vc[n]%3 != 0)
		printf("0\n");
	else
	{
		vector<ll> cnt(n+1,0);
		ll ss = vc[n]/3;
		ROF(i,n-1,2)
			if(vc[i] == (2*ss))
				cnt[i] = 1;
		ROF(i,n-2,1)
			cnt[i] += cnt[i+1];
		FOR(i,1,n-2)
			if(vc[i] == ss)
				ans += cnt[i+1];
		cout<<ans<<'\n'; 
	}
}