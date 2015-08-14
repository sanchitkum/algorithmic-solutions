//http://stackoverflow.com/questions/1503007/sum-of-series-11-22-33-nn-mod-m
//http://mathworld.wolfram.com/FactorialSums.html
//http://stackoverflow.com/questions/9727962/fast-way-to-calculate-n-mod-m-where-m-is-prime
//http://en.wikipedia.org/wiki/Wilson%27s_theorem
//http://math.stackexchange.com/questions/18576/summation-involving-a-factorial-1-sum-j-1n-jj

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cctype>

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

//http://stackoverflow.com/questions/1503007/sum-of-series-11-22-33-nn-mod-m
//http://mathworld.wolfram.com/FactorialSums.html
//http://stackoverflow.com/questions/9727962/fast-way-to-calculate-n-mod-m-where-m-is-prime
//http://en.wikipedia.org/wiki/Wilson%27s_theorem
//http://math.stackexchange.com/questions/18576/summation-involving-a-factorial-1-sum-j-1n-jj

ll m;
pair<ll,ll> pval;
//bool mprime;

ll factorialmod(ll x)
{
    ll res = pval.sc;
    ll i;
    if(x+1 < m)
    {
        dfore(i,pval.fs,x+1) // Summation from 1 to n over (k*k!)  =  (n+1)! - 1
        {
            res = ((res%m) * (i%m))%m;
        }
        pval.fs = i;
        pval.sc = res;
    }
    else if (x+1 > m) // then m divides (x+1)!, so (x+1)!%m = 0
        res = 0;
    else
        res = m; // if x+1 == m then on ((x+1)!-1)%m should be m-1;
    //res = ((res%m) - (1%m))%m;
    res = (res - (1%m))%m;
    return res;
}

ll summationmod(ll x)
{
    ll x1 = x;
    ll y = x+1; // n*(n*(n+1)/2)
    if(y%2 == 0)
        y = y/2;
    else
        x = x/2;
    ll res = ( ( ( (x%m) * (x1%m) )%m ) *(y%m))%m;
    return res;
}

/*
bool isprime(ll m)
{
    fore(i,2,sqrt(m))
    {
        if(m%i == 0)
            return false;
    }
    return true;
}
*/

int main()
{
    ll n,p;
    vll v;
    gl(n); gl(m);
    rep(n)
    {
        gl(p);
        v.pb(p);
    }
    //mprime = isprime(m);
    sort(all(v));
    ll res = 0;
    pval.fs = 1;
    pval.sc = 1;
    forup(i,0,n)
    {
        ll val1 = factorialmod(v[i]);
        ll val2 = summationmod(v[i]);
        res = ( (res%m) +  (val1%m) + (val2%m) ) % m;
    }
    pln(res);
}
