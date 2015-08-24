#include <bits/stdc++.h>
typedef long long ll;
#define get(a) scanf("%ld", &a)
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

int main()
{
	int x1,y1,x2,y2;
	int x3,y3,x4,y4;
	
	cin>>x1>>y1>>x3>>y3;

	x2 = x3;
	y2 = y1;
	x4 = x1;
	y4 = y3;

	int x5,y5,x6,y6;
	int x7,y7,x8,y8;

	cin>>x5>>y5>>x7>>y7;

	x6 = x7;
	y6 = y5;
	x8 = x5;
	y8 = y7;

	int flag = 0;
	if(x5 >= x1 && x5 <= x2 && y5 <= y1 && y5 >= y3)
		flag = 1;
	else if(x6 >= x1 && x6 <= x2 && y6 <= y1 && y6 >= y3)
		flag = 1;
	else if(x7 >= x1 && x7 <= x2 && y7 <= y1 && y7 >= y3)
		flag = 1;
	else if(x8 >= x1 && x8 <= x2 && y8 <= y1 && y8 >= y3)
		flag = 1;
	if(flag)
		cout<<"overlap";
	else
		cout<<"no overlap";
}