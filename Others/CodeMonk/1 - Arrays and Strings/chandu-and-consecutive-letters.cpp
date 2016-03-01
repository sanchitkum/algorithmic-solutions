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
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		if(s.length() == 0)
			{ cout << s << '\n'; continue; }
		char old = s[0];
		cout << s[0];
		for(int i = 1; i < s.length(); i++){
			if(s[i] == old)
				continue;
			cout << s[i];
			old = s[i];
		}
		cout << '\n';
	}	
}