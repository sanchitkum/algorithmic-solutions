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

vector<string> arr;
vector<string> arr_new;
int r,c;

int gx[] = {0,-1,0,+1};
int gy[] = {1,0,-1,0};

bool validate(int x, int y){
	if(x >= 0 && x < r && y >= 0 && y < c)
		return true;
	return false;
}

void traverseArr(){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(arr[i][j] == 'X'){ // Check its neighbours
				int cnt = 0;
				for(int k = 0; k < 4; k++){ // All 4 directions
					int nx = i + gx[k];
					int ny = j + gy[k];
					if(validate(nx,ny)){
						if(arr[nx][ny] == '.') // if water
							cnt++;
					}
					else // Not valid, i.e, boundary region so water
						cnt++;
				}		
				if(cnt >= 3) // More than 3 water region
					arr_new[i][j] = '.'; // Change in new vector string
			}
		}
	}
}

int main(){
	cin >> r >> c;
	FOR(i,1,r){
		string s; cin >> s;
		assert(s.length() == c);
		arr.pb(s);
	}
	arr_new = arr;
	traverseArr();

	// Find the smallest rectangle
	int minx = 9;
	int maxx = 0;
	int miny = 9;
	int maxy = 0;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(arr_new[i][j] == 'X'){
				minx = min(minx,i);
				maxx = max(maxx,i);
				miny = min(miny,j);
				maxy = max(maxy,j);
			}
		}
	}

	FOR(i,minx,maxx){
		FOR(j,miny,maxy)
			cout << arr_new[i][j];
		cout << '\n';
	}
}