#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%lld", &a)
#define repVector(v)  for( typeof((v).begin()) it = v.begin(); it != v.end(); it++ )
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

ll lucky[3001] = {0};
ll mark[33810] = {0};

void Findlucky(){
	ll pos = 1;
	FOR(i,2,33809){
		if(!mark[i]){
			lucky[pos] = i;
			mark[i] = 1;
			pos++;
			ll cnt = 0;
			//cout<<i<<"  ";debug(lucky[pos-1]);
			if(i==2){
				for(ll j=i; j<=33809; j++){
					if(!mark[j])
						cnt++;
					if( (cnt%i) == 0)
						mark[j] = 1;
				}
			}
			else{
				for(ll j=i; j<=33809; j+=2){
					if(!mark[j])
						cnt++;
					if( (cnt%i) == 0)
						mark[j] = 1;
				}
			}
		}
	}
}


int main(){
	ll n;
	Findlucky();
	while(true){
		cin>>n;
		if(n==0)
			break;
		cout<<lucky[n]<<'\n';
	}
}