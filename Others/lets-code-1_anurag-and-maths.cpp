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
	vector<int> two,three;

	for(int i = 16; i <= 99; i += 8)
		two.pb(i);
	for(int i = 104; i <= 999; i += 8)
		three.pb(i);

	while(t--){
		int flag = 0;
		string s; cin >> s;
		map<char,int> m;
		for(int i = 0; i < s.length(); i++){
			m[s[i]]++;
		}
		if(s.length() == 1){
			if(s == "8")
				flag = 1;
		}
		else if(s.length() == 2){
			for(int i = 0; i < two.size(); i++){
				int val = two[i];
				map<char,int> mm = m;
				int cnt = 0;
				while(val){
					if(mm[ val%10 + '0' ])
						{ cnt++; mm[ val%10 + '0' ]--; }
					val /= 10;
				}
				if(cnt == 2)
					{ flag = 1; break; }
			}	
		}
		else{
			for(int i = 0; i < three.size(); i++){
				int val = three[i];
				map<char,int> mm = m;
				int cnt = 0;
				while(val){
					if(mm[ val%10 + '0' ])
						{ cnt++; mm[ val%10 + '0' ]--; }
					val /= 10;
				}
				if(cnt == 3)
					{ flag = 1; break; }
			}	
		}

		if(flag == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
}