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
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

//Could also use pair<ll,ll>
struct point{
	ll F,S;
};

vector< point > v;

// Find if all coordinates belong in that quadrant or not
bool findRegion(point p, ll a, ll b){
	for(auto q : v){
		if( (q.F - p.F)*a < 0 )
			return 0;
		else if( (q.S - p.S)*b < 0 )
			return 0;
	}
	return 1;
}

int main(){
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll x,y;
		v.clear();
		point BL,BR,TL,TR;
		BL.F = LLONG_MAX; BL.S = LLONG_MAX;
		BR.F = LLONG_MIN; BR.S = LLONG_MAX; 
		TL.F = LLONG_MAX; TL.S = LLONG_MIN; 
		TR.F = LLONG_MIN; TR.S = LLONG_MIN;

		ll pBL,pBR,pTL,pTR;

		FOR(i,1,n){
			cin>>x>>y;
			point p;
			p.F = x; p.S = y;
			v.pb(p);

			// Bottom Left
			if(y < BL.S) 
				{ BL = p; pBL = i;}
			else if(y == BL.S && x < BL.F)
				{ BL = p; pBL = i;}

			// Bottom Right
			if(y < BR.S) 
				{ BR = p; pBR = i;}
			else if(y == BR.S && x > BR.F)
				{ BR = p; pBR = i;}

			// Top Left
			if(y > TL.S) 
				{ TL = p; pTL = i;}
			else if(y == TL.S && x < TL.F)
				{ TL = p; pTL = i;}

			// Top Right
			if(y > TR.S) 
				{ TR = p; pTR = i;}
			else if(y == TR.S && x > TR.F)
				{ TR = p; pTR = i;}			
		}
		
		if( findRegion(BL,+1,+1) ) // NE
			cout<<"1\n"<<pBL<<" NE\n";			
		else if( findRegion(BR,-1,+1) ) // NW
			cout<<"1\n"<<pBR<<" NW\n";
		else if( findRegion(TL,+1,-1) ) //SE
			cout<<"1\n"<<pTL<<" SE\n";
		else if( findRegion(TR,-1,-1) ) //SW
			cout<<"1\n"<<pTR<<" SW\n";
		else{
			if( TL.F <= BR.F )
				cout<<"2\n"<<pTL<<" SE\n"<<pBR<<" NW\n";
			else
				cout<<"2\n"<<pTL<<" SW\n"<<pBR<<" NE\n";
		}	
	}
}