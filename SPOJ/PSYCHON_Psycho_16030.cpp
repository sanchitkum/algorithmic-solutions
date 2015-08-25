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

vll prime; // All prime numbers

void sieve(ll n)
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
            for(int j=i*i; j<=n; j+=i)
                v[j] = false;
        }
    }
    /*
    for(;i<=n;i++)
        if(v[i])
            prime.pb(i);
    */
}

int main()
{
    ll t,n;
    gl(t);
    //sieve(10000001);
    while(t--)
    {
        ll even,odd;
        even = odd = 0;
        gl(n);
        //int flag = 0;
        for(ll i=2; i<=sqrt(n) && n != 1; i++)
        {
            ll cnt=0;
            while(n != 0 && n != 1 && n%i == 0)
            {
                cnt++;
                n = n/i;
            }
            if(cnt)
            {
                if(cnt%2 == 0)
                    even++;
                else
                    odd++;
                //flag = 1;
            }
        }
        if(n != 1)
            odd++;
        if(even>odd)
            cout<<"Psycho Number\n";
        else
            cout<<"Ordinary Number\n";
    }
}
