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

vll prime; // Will hold prime numbers till 100000
vll primeinrange;

void sieve(int n)
{
    vector<bool> v(n+1,1);
    v[0] = false;
    v[1] = false;
    ll i;
    dfore(i,2,sqrt(n))
    {
        if(v[i])
        {
            prime.pb(i);
            for(int j = i*i; j <= n; j+=i)
                v[j] = false;
        }
    }
    for(;i<=n;i++)
        if(v[i])
            prime.pb(i);
}

void segmentSieve(int m, int n)
{
    primeinrange.clear(); // To clear the vector which holds prime in the range
    vector<bool> vrange(n-m+1,1);
    for(vll::iterator it=prime.begin(); *it<=sqrt(n) && it != prime.end(); ++it)
    {
        //cout<<"Inside iterator prime: "<<*it;pn;
        ll s = m / *it;
        s *= *it;
        for(int j = s; j<=n ; j+= *it)
        {
            //cout<<"Value of s: "<<j;pn;
            if(j<m || j == *it)
                continue;
            vrange[j-m] = false;
        }
    }
    forup(i,0,n-m+1)
    {
        if(i+m == 1)
            continue;
        if(vrange[i])
            primeinrange.pb(i+m);
    }
}

int main()
{
    int t;
    ll m,n;
    gi(t);
    sieve(100000); // Calculate all prime numbers upto this number
    while(t--)
    {
        gl(m); gl(n);
        segmentSieve(m,n);
        //for(vll::iterator it=primeinrange.begin(); it != primeinrange.end(); ++it)
        for(auto it: primeinrange)
        {
                pln(it); // pln(*it)
        }
        pn;
    }
}
