#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define F first
#define S second
#define mp make_pair
using namespace std;

bool mycomp(string a, string b){
	if(a.size() != b.size()) // If not equal sort based on size
		return a.size() > b.size();
	else // If equal sort lexographically
		return a < b;
}

bool compSize(string a, string b){ // Sort based on size
	return a.size() <= b.size();
}

int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string> v(n);
		FOR(i,0,n-1)
			cin >> v[i];
		sort(all(v),compSize); // To sort based on size to find the substrings of smallest string

		// FOR(i,0,v.size()-1)
		// 	debug(v[i]);

		string s = v[0];
		vector<string> substrings;
		for(int i = 0; i < s.size(); i++){ // Find all substrings
			for(int len = s.size() - i; len >= 1; len--){
				substrings.pb(s.substr(i,len));
			}
		}

		sort(all(substrings),mycomp);

		// FOR(i,0,substrings.size()-1)
		// 	debug(substrings[i]);

		string str;
		FOR(i,0,substrings.size()-1){
			str = substrings[i];
			int allvector = 0; // Count of number of vector having this particular substring
			int len = str.size(); // The length of this substring
			FOR(i,1,n-1){
				s = v[i];
				int flag = 0;
				for(int i = 0; i < s.size(); i++){ // Find all substrings of this
					if( str == s.substr(i,len) ) // Find substrings of length of the given string
						{ flag = 1; break; }
				}
				if(flag) allvector++; // One more element has this string
			}
			if(allvector == n-1)
				break;
		}

		cout << str << '\n';
	}	
}