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

vector<int> prime;
vector<int> mark_prime(10000,1);
vector<int> adj[10000];
int mark_bfs[10000];
int depth[10000];
int a,b; 

void sieve(){
	for(int i = 2; i <= 9999; i++){
		if(mark_prime[i]){
			if(i >= 1000)
				prime.pb(i);
			for(int j = i*i; j <= 9999; j += i)
				mark_prime[j] = 0;
		}
	}
}

bool bfs(){
	queue<int> q;
	q.push(a);
	mark_bfs[a] = 1;
	depth[a] = 0;

	int flag = 0;
	int temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp == b){
			flag = 1; break;
		}
		for(auto p : adj[temp]){
			if(!mark_bfs[p]){
				q.push(p);
				depth[p] = depth[temp] + 1;
				mark_bfs[p] = 1;
			}
		}
	}
	if(flag)
		return true;
	else
		return false;
}

int main(){
	sieve();
	// Precomputation of the network, change of one digit and is prime
	for(int i = 0; i < prime.size(); i++){
		int val = prime[i];
		int temp_val = prime[i];
		int base_position = 1;
		for(int j = 0; j < 4; j++){
			int rem = temp_val % 10;
			int subtract_value = rem*base_position;
			for(int i = 0; i <= 9; i++){
				if(i == 0 && base_position == 1000) // First digit cannot be zero
					continue;
				if(i == rem) // No self loop
					continue;
				int additive_value = i*base_position;
				int new_value = val - subtract_value + additive_value; 
				if(mark_prime[new_value])
					adj[val].pb(new_value);
			}
			base_position *= 10;
			temp_val /= 10;
		}
	}
	int t; cin >> t;
	while(t--){
		cin >> a >> b;
		memset(mark_bfs,0,sizeof(mark_bfs));
		memset(depth,0,sizeof(depth));
		if(bfs())
			cout << depth[b] << '\n';
		else
			cout << "Impossible\n";
	}
}