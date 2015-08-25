#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>

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
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )

#define gi(n) scanf("%d",&n)
#define gl(n) cin>>n

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int t;
    ll n,m;
    gi(t);
    while(t--)
    {
        gl(n); gl(m);
        ll num = 1;
        ll den = 1;
        forup(i,1,n)
        {
            num = (num + den) % m;
            den = (num + den) % m;
        }
        /*
        ll gcdval = gcd(num,den);
        num = num/gcdval;
        den = den/gcdval;
        */
        num = num%m; den = den%m;
        cout<<num<<"/"<<den;pn;
    }
}
