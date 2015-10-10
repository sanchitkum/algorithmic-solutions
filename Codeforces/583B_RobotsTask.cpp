#include <bits/stdc++.h>
typedef long long ll;
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

int main(){
	ll n; cin >> n;
	vector<ll> v;
	vector<ll> visit(n,0);
	FOR(i,1,n){
		ll val; cin >> val;
		v.pb(val);
	}
	int ans = 0;
	int cnt = 0;
	while(cnt < n){
		ll i = 0;
		while(i < n && cnt < n){
			if(visit[i] == 0 && v[i] <= cnt){
				cnt++;
				visit[i] = 1;
			}
			i++;
		}
		if(cnt < n)
			ans++;
		i = n-1;
		while(i >= 0 && cnt < n){
			if(visit[i] == 0 && v[i] <= cnt){
				cnt++;
				visit[i] = 1;
			}
			i--;
		}
		if(cnt < n)
			ans++;
	}
	cout<<ans;
}