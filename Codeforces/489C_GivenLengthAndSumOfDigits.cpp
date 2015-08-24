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
#define gl(n) cin>>x
#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

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
	int m,s;
	gi(m); gi(s);
	int sc = s; // copy of s;

	if(s == 0 && m == 1) // Exception Case
		{ printf("0 0\n"); return 0; }
	if(s == 0 || s > (9*m))
		{ printf("-1 -1\n"); return 0; }

	// For MIN
	fore(i,1,m)
	{
		if(i == 1)
		{
			fore(j,1,9)
			{
				if(s-j <= 9*(m-i))
				{
					cout<<j;
					s = s- j;
					break;
				}
			}
		}
		else
		{
			fore(j,0,9)
			{
				if(s-j <= 9*(m-i))
				{
					cout<<j;
					s = s- j;
					break;
				}
			}
		}	
	}
	ps;

	// For MAX
	s = sc;
	fore(i,1,m)
	{
		if(i == 1)
		{
			fordn(j,9,1)
			{
				if(s-j >= 0 && s-j <= 9*(m-i))
				{
					cout<<j;
					s = s- j;
					break;
				}
			}
		}
		else
		{
			fordn(j,9,0)
			{
				if(s-j >= 0 && s-j <= 9*(m-i))
				{
					cout<<j;
					s = s- j;
					break;
				}
			}
		}	
	}
}