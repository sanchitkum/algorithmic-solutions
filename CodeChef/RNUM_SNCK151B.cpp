#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
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
#define gl(n) scanf("%lld",&n)
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pn printf("\n");
#define ps printf(" ");

#define fs first
#define sc second
#define pb push_back

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

int main()
{
	int t,n,val;
	gi(t);
	while(t--)
	{
		gi(n);
		vi v;
		rep(i,n)
		{
			gi(val);
			v.pb(val);
		}
		sort(all(v));
		bool mark[n];
		memset(mark,0,sizeof(mark));
		int min = 0;
		int max = 0;

		//For MIN
		if(v.size() >= 3)
		{
			fore(i,0,v.size()-3)
			{
				if(!mark[i])
				{
					if(v[i+2] == v[i]+2 && v[i+1] == v[i]+1)
					{
						mark[i+2] = true;
						mark[i+1] = true;
					}
					else if(v[i+1] == v[i]+1)
						mark[i+1] = true;
					mark[i] = true;
					min++;
				}
			}
		}
		//For last two cases:
		if(v.size() >= 2)
		{
			if(!mark[v.size()-2])
			{
				if(v[v.size()-1] == v[v.size()-2]+1)
					mark[v.size()-1] = true;
				mark[v.size()-2] = true;
				min++;
			}
		}
		if(!mark[v.size()-1])
				min++;

		// For MAX
		memset(mark,0,sizeof(mark));
		if(v.size() >= 2)
		{
			fore(i,0,v.size()-2)
			{
				if(!mark[i])
				{
					if(v[i+1] == v[i]+1)
						mark[i+1] = true;
					mark[i] = true;
					max++;
				}
			}
		}
		if(!mark[v.size()-1])
			max++;
		printf("%d %d\n",min,max);
	}
}