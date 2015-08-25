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
	int n;
	gi(n);

	vll v(n);
	ll max_xor = 0;
	int s,e;
	s = e = 0;

	rep(i,n)
		gl(v[i]);

	forup(i,0,n)
	{
		ll temp = v[i];
		if(temp > max_xor)
		{
			max_xor = temp;
			s = e = i+1;
		}
		forup(j,i+1,n)
		{
			temp = (temp^v[j]);
			if(temp > max_xor)
			{
				max_xor = temp;
				s = i+1;
				e = j+1;
			}
		}
	}

	printf("%lld\n",max_xor);
	printf("%d %d\n",s,e);
}

/*
// Incorrect Logic - This is not DP like maximum contiguous sum problem!!!
int main()
{
	int n;
	gi(n);
	vll v,xor_val(n); // xor-val -> Stores the maximum contiguous xor at that particular index
	ll val,max_xor = 0;
	vector< pii > index(n);
	pii pval;
	pval.fs = pval.sc = 0;

	rep(i,n)
	{
		gl(val);
		v.pb(val);

		if(i == 0)
			{ xor_val[i] = v[0]; max_xor = v[0]; pval.fs = pval.sc = i+1; index[i] = pval; continue; }

		if( (xor_val[i-1]^v[i]) >= v[i] ) // Extend the previous window to include this index
		{
			xor_val[i] = (xor_val[i-1]^v[i]);
			pval.sc = i+1;
			index[i] = pval;
		}
		else // Start a new window
		{
			xor_val[i] = v[i];
			pval.fs = pval.sc = i+1;
			index[i] = pval;	
		}

		// Maximum XOR value
		if(xor_val[i] > max_xor)
			max_xor = xor_val[i];
	}

	rep(i,n)
		if(xor_val[i] == max_xor)
		{
			pval = index[i];
			break;
		}

	printf("%lld\n",max_xor);
	printf("%d %d\n",pval.fs,pval.sc);
}
*/