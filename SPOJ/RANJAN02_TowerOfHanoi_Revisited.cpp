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
Link: http://blog.singhanuvrat.com/problems/spoj-ranjan02-tower-of-hanoi-revisited

Explanation:
Let’s think of this problem in a recursive way.
Suppose we know of an algorithm to transfer n-1 discs from peg A to peg C in the shortest number of moves.
Now for a configuration of n discs we can use the method we know to:  [Actually this is the algorithm]

    1. Transfer the first n-1 discs to peg C
    2. Transfer the disc n to peg B
    3. Move back n-1 discs to peg A
    4. Transfer the disc n to peg C
    5. And finally transfer the n-1 discs to peg C again as we did in the first step

Let’s use the notation M_n to denote the number of moves needed to transfer n discs from peg A to peg C.
So by the above algorithm, we perform M_{n-1} moves 3 times (steps [1], [3] and [5]) and then perform 2 more moves (steps [2] and [4]).
So we can formulate the following recursive equation for the number of steps required to transfer n discs from peg A to peg C:

M_n = 3 * M_{n-1} + 2

There we are! The base is of 0 pegs where we need 0 moves.
*/

int main(){
	ll t; cin >> t;
	// Precompute and store in "ans"
	vector<ll> ans(36,0);
	for(int i = 1; i <= 35; i++){
		ans[i] = 3*ans[i-1] + 2;
	}
	while(t--){
		int n; cin >> n;
		cout << ans[n] << '\n';		
	}
}