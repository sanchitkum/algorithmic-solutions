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
	ll d,sumtime;
	cin >> d >> sumtime;
	vector< pair<ll,ll> > v;
	ll minsum = 0;
	ll maxsum = 0;
	vector<ll> ans(d);
	FOR(i,0,d-1){
		ll x,y; cin >> x >> y;
		v.pb(mp(x,y));
		minsum += x;
		maxsum += y;
		ans[i] = x;
	}
	if(sumtime < minsum || sumtime > maxsum){
		cout << "NO"; return 0;
	}

	sumtime = sumtime - minsum; // Now the required sumtime

	ll i = 0;
	while(sumtime > 0){
		ans[i] += min(v[i].S-v[i].F,sumtime);
		sumtime -= min(v[i].S-v[i].F,sumtime);
		i++;
	}

	cout << "YES\n";
	FOR(i,0,d-1){
		cout << ans[i] << " ";
	}

}