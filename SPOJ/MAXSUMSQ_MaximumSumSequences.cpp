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

#define all(v) (v).begin(),(v).end() 
#define sz(v) int((v).size()) 
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define endl '\n'

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define repIt(v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define INPFILE freopen("input.in","r",stdin)
#define OUTPFILE freopen("out.txt","w",stdout)

/*
Video Tutorial: http://people.cs.clemson.edu/~bcdean/dp_practice/dp_1.swf
Logic: http://apps.topcoder.com/forums/reg/?module=Thread&threadID=676639&start=0
*/

int main()
{
	//INPFILE;
	int t;
	gi(t);
	ll n;
	while(t--)
	{	
		gl(n);
		vll v,sum(n),ways(n); // Sum - Stores the maximum possible sum window till that particular index
		ll val;
		ll maxsum;
		rep(i,n)
		{
			gl(val);
			v.pb(val);
			
			if(i == 0)
				{ sum[i] = v[0]; ways[i] = 1; maxsum = v[0]; continue; }
			
			if(sum[i-1]+v[i] == v[i]) // Another way this value can be reached
			{
				sum[i] = sum[i-1] + v[i]; // or, v[i]
				ways[i] = ways[i-1] + 1; 
			}
			else if( sum[i-1]+v[i] > v[i] ) // Extend the previous window since sum is increasing
			{
				sum[i] = sum[i-1] + v[i];
				ways[i] = ways[i-1];  // Since extending, same as previous ways
			}
			else // Start as new window
			{
				sum[i] = v[i];
				ways[i] = 1; // Since starting a new window there is only one way
			}

			// Finding the maximum sum value
			if(sum[i] > maxsum)
				maxsum = sum[i];
		}

		ll cnt = 0;
		rep(i,n)
			if(sum[i] == maxsum)
				cnt += ways[i];

		printf("%lld %lld\n",maxsum,cnt);
	}
}