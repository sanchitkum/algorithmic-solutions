#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		vector<ll> v;
		for(ll i = 0; i < n; i++) {
			ll val; cin>>val;
			v.push_back(val);
		}
		vector<ll> sub(v.size(),1);
		for(ll i = 1; i < v.size(); i++) {
			if(v[i] >= v[i-1])
				sub[i] += sub[i-1];
		}
		ll sum = 0;
		for(ll i = 0; i < v.size(); i++) {
			sum += sub[i];
		}
		cout<<sum<<'\n';
	}
}