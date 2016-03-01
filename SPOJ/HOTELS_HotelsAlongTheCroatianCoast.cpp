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
	ll n,m; cin >> n >> m;
	vector<ll> v(n);
	FOR(i,0,n-1)
		cin >> v[i];
	ll i = 0; ll j = 0;
	ll max_sum = 0;
	ll sum = 0;

	// Initially, move i to place where it can start
	while(i < n && v[i] > m)
		i++;

	for(j = i; j < n; j++){
		sum += v[j];
		if(sum > m){ // If it exceeds the limit
			while(sum > m){
				sum -= v[i];
				i++;
			}
		}
		max_sum = max(max_sum,sum);
	} 
	cout << max_sum;
}