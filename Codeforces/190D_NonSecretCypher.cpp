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

int main() {
    ll n,k; cin >> n >> k;
    vector<ll> v(1000006);
    FOR(i,1,n)
        cin >> v[i];

    map<ll,ll> m;
    ll j = 1;
    ll oldj = -1;
    ll ans = 0;

    for(ll i = 1; i <= n; i++){
        for(; j <= n; j++){
            if(j != oldj)
                m[v[j]]++;
            if(m[v[j]] >= k){
                ans += (n-j+1);
                oldj = j;
                break;
            }
        }
        m[v[i]]--;
        if(m[v[j]] < k)
            j++;
    }

    cout << ans;
}