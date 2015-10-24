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
	int n; cin >> n;
	map < int,vector<int> > m;
	FOR(i,1,n){
		int x; cin >> x;
		m[x].push_back(i);
	}
	int ans = 0;
	set < pair <int,int> > s;
	for(map < int,vector<int> >::iterator it = m.begin(); it != m.end(); it++){
		//debug(it->F);
		if(m[it->F].size() == 1)
			{ ans++; s.insert( mp(it->F,0) ); }
		else{
			int d = m[it->F][1] - m[it->F][0];
			//debug(d);
			int flag = 1;
			for(int i = 2; i < m[it->F].size(); ++i){
				if(m[it->F][i] - m[it->F][i-1] != d)
					{ flag = 0; break; }
			}
			//debug(it->F);
			if(flag)
				{ ans++; s.insert( mp(it->F,d) ); }
		}			
	}

	cout<<ans<<'\n';
	for(auto q : s)
		cout<<q.F<<" "<<q.S<<'\n';
}