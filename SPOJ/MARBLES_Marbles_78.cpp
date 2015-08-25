//http://coderscasediary.blogspot.in/2013/11/marbles-codechef_14.html
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
#define dfore(i,a,b) for(i=a; i<=b; i++)
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

ll calculate(ll n, ll r)
{
    ll res = 1;
    if(r > n/2)
        r = n-r; // Since, nCr = nCn-r
    forup(i,0,r)
    {
        res *= n;
        res /= i+1;
        n--;
    }
    return res;
}

int main()
{
    int t;
    gi(t);
    ll n,k,N,K;
    while(t--)
    {
        gl(n); gl(k);
        K = n-k; // Because one from each is mandatory, so K more to pick; This is our 'r'
        N = k+K-1; // This is our n+r-1 (objects available/options(n) + To pick(r) - 1 )
        pln( calculate(N,K) );  // n+r-1Cr
    }
}
