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

ll count_five(ll a)
{
	ll cnt = 0;
	while(a%5 == 0)
	{
		cnt++;
		a /= 5;
	}
	return cnt;
}

ll count_trailing_zero(ll a)
{
	ll cnt = 0;
	while(a%10 == 0)
	{
		cnt++;
		a /= 10;
	}
	return cnt;
}

int main()
{
	//INPFILE;
	int n;
	gi(n);
	ll a;
	while(n--)
	{
		gl(a);
		ll no_five = count_five(a);
		ll trailing_zero = count_trailing_zero(a);
		if(no_five == trailing_zero)
			{ pln(a); continue; }
		double required_multiplication = no_five - trailing_zero;
		required_multiplication = ceil(required_multiplication/2); // Since 2^2 = 4;
		rep(i,required_multiplication)
			a *= 4;
		pln(a);
	}	
}