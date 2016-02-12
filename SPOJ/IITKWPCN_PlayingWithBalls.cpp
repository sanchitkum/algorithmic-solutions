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
Explanation: http://code.cloudkaksha.org/spoj/spoj-iitkwpcn-solution

Let's say that black is '-' (negative) and white is '+' (positive), let us check our assumption
According to the problem, if the chosen balls belong to the same color, the ball put back will be white, else black
Going with our assumption, if two signs are same it will result in '+' (white) (-- = +) else '-' (black), which is true
So, irrespective of the order of ball chosen, if the the number of '-' balls is even, it will result in '+' else '-'.
So, we can see if the number of balls initially belonging to black is even, it will finally belong to white else black
*/

int main(){
	ll t; cin >> t;
	while(t--){
		ll w,b; cin >> w >> b;
		if(b%2 == 0)
			cout << "0.000000\n";
		else
			cout << "1.000000\n";
	}	
}