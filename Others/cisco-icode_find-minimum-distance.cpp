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
	vector<ll> T1,T2,T3;
	ll t1,t2,t3;
	t1=t2=t3 =0;
	FOR(i,1,n)
	{
		cin>>val;
		v.pb(val);
	}
	sort(all(v));
	FOR(i,0,n-1)
	{
		val=v[i];
		t1 += -(val*val*val);
		t2 += val;
		t3 += -(val*val);
		T1.pb(t1);
		T2.pb(t2);
		T3.pb(t3);
	}

	ll ans = 0;
	ll minx = LLONG_MAX;
	FOR(i,0,n-1)
	{
		ll p = (v[i]*v[i]*v[i])*(i);
		if(i-1 >= 0)
			p += T1[i-1];
		if(i-1 >= 0)
			p -= 3*v[i]*(v[i]*T2[i-1]+T3[i-1]);

		ll q = -(v[i]*v[i]*v[i])*(n-i-1);
		q -= T1.back() - T1[i];
		q += 3*v[i]*( v[i]*(T2.back() - T2[i]) + T3.back() - T3[i]);
		if(p+q < minx)
			minx = p+q, ans = v[i];
	}
	
	ll a = v[0] + v[n-1]/2;
	ll b = ans;
	ll ansA = 0;
	ll ansB = 0;
	
	FOR(i,0,n-1)
	{
		val = abs(v[i] - a);
		ansA += pow(val,3);
		val = abs(v[i] - b);
		ansB += pow(val,3);
	}
	if(ansA < ansB)
		cout<<a;
	else
		cout<<b;
}
