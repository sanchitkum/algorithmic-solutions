#include <bits/stdc++.h>
typedef long long ll;
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define F first
#define S second
#define mp make_pair
using namespace std;

int main(){
	ll r,x1,y1,x2,y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	ll xd = abs(x1-x2);
	ll yd = abs(y1-y2);
	double d = pow(xd,2) + pow(yd,2);
	d = sqrt(d);
	ll ans = ceil(d/(2*r));
	cout << ans;
}