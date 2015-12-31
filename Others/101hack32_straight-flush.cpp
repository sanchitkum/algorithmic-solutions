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
	vector<string> s;
	FOR(i,1,5){
		string str; cin >> str;
		s.pb(str); 
	}
	int flag = 1;
	FOR(i,0,3){
		if(s[i][1] != s[i+1][1])
			{flag = 0; break;}
	}
	if(flag == 0)
		{cout << "NO"; return 0;}
	
	vector<int> mark(15,0);
	FOR(i,0,4){
		if(s[i][0] != 'T' && s[i][0] != 'J' && s[i][0] != 'Q' && s[i][0] != 'K' && s[i][0] != 'A')
			mark[s[i][0] - 48] = 1;
		else if(s[i][0] == 'T')
			mark[10] = 1;
		else if(s[i][0] == 'J')
			mark[11] = 1;
		else if(s[i][0] == 'Q')
			mark[12] = 1;
		else if(s[i][0] == 'K')
			mark[13] = 1;
		else if(s[i][0] == 'A')
			mark[1] = 1;
	}
	flag = 0;
	FOR(i,1,9){
		if(mark[i] == 1 && mark[i+1] == 1 && mark[i+2] == 1 && mark[i+3] == 1 && mark[i+4] == 1)	
			{flag = 1; break;}
	}
	if(mark[10] == 1 && mark[11] == 1 && mark[12] == 1 && mark[13] == 1 && mark[1] == 1)	
			flag = 1;	

	if(flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}