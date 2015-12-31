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
		ll n; cin >> n;
		string s = "";
		while(n > 0){
			int rem = n % 5;
			if(rem == 0)
				n = (n/5)-1;
			else
				n /= 5;
			switch(rem){
				case 0: s += "u"; break;
				case 1: s += "m"; break;
				case 2: s += "a"; break;
				case 3: s += "n"; break;
				case 4: s += "k"; break;
			}
		}
		reverse(all(s));
		cout << s << '\n';;
	}	
}