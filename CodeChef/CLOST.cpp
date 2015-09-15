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

struct range
{
	ll x,y,diff;
};

bool cmp(range a, range b)
{
	return a.diff < b.diff;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll str[2005] = {0};
		range query[k];
		FOR(i,0,k-1){
			cin>>query[i].x>>query[i].y;
			query[i].diff = query[i].y - query[i].x - 1;
			str[query[i].x] = 1; // 1 -> '('
			str[query[i].y] = -1; // -1 -> ')'
		}
		sort(query,query+k,cmp);
		FOR(i,0,k-1){
			ll start = query[i].x;
			ll end = query[i].y;
			ll count = 0;
			FOR(j,start,end){
				count += str[j];
				if(str[j] == 0){
					if(count > 0)
						{str[j] = -1; count--;}
					else
						{str[j] = 1; count++;}
				}
			}
		}
		FOR(i,0,n-1){
			if(str[i] == 0)
				str[i] = 1; // Put anything since not in range
		}

		FOR(i,0,n-1){
			if(str[i] == 1)
				cout<<'(';
			else
				cout<<')';
		}
		cout<<'\n';
	}
}