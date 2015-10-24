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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> Tprime;
ll n = 100001;
vector<bool> mark(n+1,0);

void sieve(){
    for(ll i = 2; i <= n; i++){
        if(!mark[i]){
            Tprime.pb(i*i);
            for(ll j = i*i; j <= n; j += i){
                mark[j] = 1;
            }
        }
    }
}


int main(){
	sieve();
	ll q; cin >> q;
	while(q--){
		ll l,r; cin >> l >> r;
		ll low = lower_bound(all(Tprime),l) - Tprime.begin();
		ll high = lower_bound(all(Tprime),r) - Tprime.begin();
		if(Tprime[high] > r)
			high--;
		//debug(Tprime[low]);
		//debug(Tprime[high]);
		cout << high - low + 1 << '\n';
	}
}