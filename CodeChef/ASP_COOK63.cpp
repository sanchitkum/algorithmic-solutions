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

int main(){
	ll t; get(t);
	while(t--){
		ll n; get(n);
		vector<ll> v(n+1);
		
		FOR(i,1,n)
			get(v[i]);

		vector<ll> mark(n+1,0);
		bool flag = true;

		FOR(i,1,n-1){
			/*
			if(v[i] <= v[i+1]) // Already sorted order
				continue;
			else */
			if (v[i] > v[i+1] && mark[i] == 0){
				mark[i+1] = 1;
				swap(v[i],v[i+1]);
			}
			else if (v[i] > v[i+1] && mark[i] == 1){
				flag = false;
				break;
			}
		}

		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}