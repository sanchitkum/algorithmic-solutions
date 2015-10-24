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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main(){
	ll m; cin >> m;
	map<string,ll> vote;
	FOR(i,1,m){
		string s; cin >> s;
		vote[s]++;
	}
	for(auto q : vote){
		if(q.S > m/2){
			cout << q.F; break;
		}
	}
}