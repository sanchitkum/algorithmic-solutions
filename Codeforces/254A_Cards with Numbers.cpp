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
#define pin(x) printf("%d\n",x)
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
#define INPFILE freopen("input.txt","r",stdin)
#define OUTPFILE freopen("output.txt","w",stdout)

int main()
{
	INPFILE;
	OUTPFILE;
	long int n;
	scanf("%ld",&n);
	map<long int,long int> m;
	map<long int, vector<long int> > m_i;
	long int val;
	for (long int i=0; i< (2*n); i++)
	{
		scanf("%ld",&val);
		m[val]++;
		m_i[val].pb(i+1);
	}
	int flag = 0;
	repIt(m)
	{
		if( (it->sc)% 2 )
			{ flag = 1; break; }
	}
	if(flag)
		printf("-1\n");
	else
	{
		repIt(m)
		{
			int i = 0;
			while(it->sc)
			{
				printf("%ld %ld\n", m_i[it->fs][i], m_i[it->fs][i+1] );
				i += 2;
				it->sc -= 2;
			}
		}	
	}
}