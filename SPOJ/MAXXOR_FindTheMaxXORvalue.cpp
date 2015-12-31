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

/*
Explanation:
In the bit representation from left to right, the common beginning parts of bits which are same will become zero,
and at the point at which difference in bits, we can get the maximum XOR value.

0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111

*/

int main(){
	ll l,r; cin >> l >> r;
	int lbits[32];
	int rbits[32];
	for(int i = 0; i < 32; i++){
		lbits[i] = l & 1;
		rbits[i] = r & 1;
		l >>= 1; // Right shift
		r >>= 1; 
	}
	ll ans = 0;
	for(int  i = 31; i >= 0; i--){
		if(lbits[i] != rbits[i]){
			ans = (1 << (i+1)) - 1; // 2^(i+1) - 1; 
			break;
		}
	}
	cout << ans << '\n'; 
}