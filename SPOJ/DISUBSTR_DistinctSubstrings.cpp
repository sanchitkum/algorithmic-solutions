#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )

#define gi(n) scanf("%d",&n)
//#define gl(n) cin>>n
#define gl(n) scanf("%lld",&n)

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

#define matrix vector< vector<ll> >
#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11

#define INPFILE freopen("input.in","r",stdin)

//Learn more here: http://www.cs.umd.edu/class/fall2011/cmsc858s/SuffixArrays.pdf

vector<string> suffix;
vi lcp;

void longest_common_prefix(string s1, string s2) // Computes longest common prefix for two strings
{
    int len = min(s1.length(), s2.length());
    int cnt = 0;
    forup(i,0,len)
    {
        if(s1[i] != s2[i])
            break;
        cnt++;
    }
    lcp.pb(cnt);
}

void compute_lcp()
{
    lcp.pb(0); // First element can have no common prefix, as no previous element exists
    forup(i,1,suffix.size())
        longest_common_prefix(suffix[i-1],suffix[i]); // LCP of previous and current suffix (in sorted order)
}

int main()
{
    int t;
    gi(t);
    cin.ignore();
    string s;
    while(t--)
    {
        suffix.clear();
        lcp.clear();
        getline(cin,s);
        forup(i,0,s.length())
            suffix.pb(s.substr(i)); // Substring from i position till the end
        sort(all(suffix));
        compute_lcp();
        ll substring = 0;
        forup(i,0,suffix.size())
            substring += suffix[i].length() - lcp[i]; // Remove the common prefix to avoid repetation cases
        pln(substring);
    }
}
