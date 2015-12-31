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

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string ans;
		FOR(i,1,n){
			string s; cin >> s;
			if(i == 1)
				ans = s;
			else{
				string common = "";
				for(int j = 0; j < s.length() && j < ans.length(); j++){
					if(s[j] != ans[j])
						break;
					common += s[j];
				}
				ans = common;
			}
		}
		cout << ans << '\n';
	}
}