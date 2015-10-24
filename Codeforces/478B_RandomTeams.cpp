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
	ll n,m; cin >> n >> m;
	ll kmax,kmin;

	ll single_team_max = n-m+1;
	kmax = single_team_max*(single_team_max-1)/2;

	ll q = n / m;
	ll r = n - (m*q);

	kmin = ( (m-r)*(q)*(q-1)/2 ) + ( r*(q+1)*(q)/2 );

	cout << kmin << " " << kmax;
}