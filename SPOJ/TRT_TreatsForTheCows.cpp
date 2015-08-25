#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>=b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>=b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define gi(n) scanf("%d",&n)
#define gl(n) cin>>n
#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define endl '\n'

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define boost ios::sync_with_stdio(0)
#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)
#define OUTPFILE freopen("out.txt","w",stdout)

// Logic: https://www.quora.com/Are-there-any-good-resources-or-tutorials-for-dynamic-programming-besides-the-TopCoder-tutorial

int n;
vi price;
int dp[2000][2000];

int profit(int be, int en)
{
	if(be>en) // Base case
		return 0; 
	if(dp[be][en] != -1)
		return dp[be][en];
	int day = n - (en-be+1) + 1;
	return dp[be][en] = max( profit(be+1,en) + (price[be]*day) , profit(be,en-1) + (price[en]*day) );
}

int main()
{
	//INPFILE;
	memset(dp,-1,sizeof(dp));	
	int val;
	gi(n);
	rep(i,n)
	{
		gi(val);
		price.pb(val);
	}
	int ans = profit(0,n-1);
	pin(ans);
}