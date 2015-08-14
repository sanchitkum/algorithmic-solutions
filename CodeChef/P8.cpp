#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(n) for(ll i=0; i<n; i++)
 
#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)
 
#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
 
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
 
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pn printf("\n")
#define ps printf(" ")
 
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
int main()
{
    string s;
    while(true)
    {
        getline(cin,s);
        if(s == "00e0")
            break;
        ll no = (s[0]-48)*10 + (s[1]-48);
        no = no*pow(10,(s[3]-48));
        ll logval = log2(no);
        ll p = pow(2,logval);
        ll ans = 1 + (no-p)*2;
        pln(ans);
    }
}