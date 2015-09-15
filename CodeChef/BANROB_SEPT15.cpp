#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( typeof((v).begin()) it = v.begin(); it != v.end(); it++ )
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

double fast_exp(double base, ll exp){
	double res = 1;
	while(exp > 0){
		if(exp%2) res *= base;
		base *= base;
		exp /= 2;
	}
	return res;
}

int main(){
	ll t; cin>>t;
	while(t--){
		ll m;
		double p;
		cin>>m>>p;
		double billion = 1000000000;
		double a = billion * (1 - fast_exp(-p,m)) / (1 - (-p));
		double b = billion - a;
		printf("%.2lf %.2lf\n",a,b);
	}
}