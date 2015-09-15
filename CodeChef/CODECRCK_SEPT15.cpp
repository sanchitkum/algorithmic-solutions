#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
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

double fast_pow(double base, ll exp){
	double res = 1;
	while(exp>0){
		if(exp%2) res *= base;
		base *= base;
		exp >>= 1;
	}
	return res;
}

int main(){
	ll m,k,s;
	cin>>m>>k>>s;
	double am,bm;
	cin>>am>>bm;
	double ak,bk;
	ll n,r;
	double x = sqrt(2);
	double y = sqrt(3);

	if(m%2 != k%2){
		ak = x*(am + bm) - x*y*(am - bm);
		bm = x*(am - bm) + x*y*(am + bm);
		am = ak;
		m = m+1;
	}

	n = (k-m)/2;
	r = n*4;

	double ans = am + bm;
	ll it = r-s;
	//debug(it);
	if(it < 0){
		while( ans > 0.001 && abs(it) > 0 ){
			ans = ans/2;
			it++;
		}
	}
	else{
		ans *= fast_pow(2,it);
	}

	printf("%.2lf\n",ans);
}