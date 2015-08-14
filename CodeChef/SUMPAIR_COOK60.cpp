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

int main()
{
	//INPFILE;
	int t,n,d;
	gi(t);
	while(t--)
	{
		gi(n); gi(d);
		vi arr;
		int val;
		bool mark[n];
		memset(mark,0,sizeof(mark));
		rep(i,n)
		{
			gi(val);
			arr.pb(val);
		}
		sort(arr.rbegin(),arr.rend());
		ll sum = 0;
		forup(i,0,arr.size())
		{
			if(!mark[i])
			{	
				forup(j,i+1,arr.size())
				{
					if( !mark[j] && (arr[i] - arr[j]) < d )
					{
						sum = sum + arr[i] + arr[j];
						mark[i] = mark[j] = 1;
						break;
					}
					else if( (arr[i] - arr[j]) >= d )
						break;
				}
			}
		}
		pln(sum);
	}
}
