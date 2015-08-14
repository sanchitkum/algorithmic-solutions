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
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k,need;
		cin>>n>>k;

		ll current_available = k;
		current_available++; // To start with k inside the loop for the first time.
		ll packets;
		ll total_packets = 1;

		rep(i,n)
		{
			current_available--; //Decay each day
			cin>>need;

			if(current_available <= 0)
				{ current_available = k; total_packets++; }

			if(need >= current_available)
			{
				need -= current_available;
				current_available = 0;
				packets = ceil((double)need/k);
				total_packets += packets;
				current_available = (packets*k) - need;
			}
			else
				current_available -= need;
		}
		pln(total_packets);
	}
}

/* 
//WA because of incorrect assumption
int main()
{
	INPFILE;
	int t;
	gi(t);
	while(t--)
	{
		ll n,k,need;
		//vll diet;
		//vll leftover;
		gl(n); gl(k);
		double packets = 0;
		ll total_packets = 0;
		ll current_available = 0;
		ll this_available = 0;
		rep(i,n)
		{
			gl(need);
			if(current_available >= need)
			{ 
				current_available -= need;
				need = 0;
				if(current_available)
					current_available--;
			}
			else if( (need%k) != 0 && current_available >= (need%k) )
			{
				current_available -= (need%k);
				need -= (need%k);
				if(current_available)
					current_available--;
			}
			if(need)
			{
				packets = ceil((double)need/k);
				total_packets += packets;
				this_available = ((k * packets) - need);
				if(this_available)
					this_available--; // Decay
				current_available += this_available;
			}
		}
		pln(total_packets);
	}	
} 
*/