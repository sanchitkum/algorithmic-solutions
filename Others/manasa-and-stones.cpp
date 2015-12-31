#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll t; cin >> t;
	while(t--){
		ll n,a,b; cin >> n >> a >> b;
		set<ll> s[n+1];
		s[1].insert(0); // First element is 0;
		for(int i = 2; i <= n; i++){
			for(auto p : s[i-1]){
				s[i].insert(p+a);
				s[i].insert(p+b);
			}
		}
		for(auto p : s[n])
			cout << p << " ";
		cout << '\n';
	}
}