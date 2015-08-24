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
#define gl(n) cin>>n

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
#define MOD 1000000007

#define INPFILE freopen("input.in","r",stdin)

int main()
{
    //INPFILE;
    string s,sc; //sc is copy of s in reverse order
    getline(cin,s);
    sc = s;
    reverse(all(sc));
    string t;
    getline(cin,t);
    ll i,j;
    j = 0;
    for(i=0; i<t.length(); i++)
    {
        if(t[i] == s[j])
            j++;
        if( j == s.length() )
            break;
    }
    if(j != s.length())
        { printf("0"); return 0; }
    ll left_pos = i; // Mark its left pos
    // Do for reverse
    j = 0;
    for(i = t.length()-1; i >= 0; i--)
    {
        if(t[i] == sc[j])
            j++;
        if( j == sc.length() )
            break;
    }
    if(j != sc.length())
        { printf("0"); return 0; }
    ll right_pos = i;// Mark its right pos
    if(right_pos-left_pos > 0)
        cout<<right_pos-left_pos;
    else
        printf("0");
    return 0;
}
