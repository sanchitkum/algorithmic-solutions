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

ll trailingZeroes(ll k)
{
    ll cnt = 0;
    for(ll i = 5; i <= k; i*= 5)
    {
        cnt = cnt + k/i;
    }
    return cnt;
}

ll lastdigit(ll a, ll b)
{
    string four = "64",nine = "19",two = "6248",three = "1397",seven = "1793",eight = "6842";
    a%=10;
    if (a==0 && b==0) return 1;
    else if (b==0) return 1;
    else if(a==0 || a==1 || a==5 || a==6) return a;
    else if(a==4) return (four[b%2]-48);
    else if(a==9) return (nine[b%2]-48);
    else if(a==2) return (two[b%4]-48);
    else if(a==3) return (three[b%4]-48);
    else if(a==7) return (seven[b%4]-48);
    else if(a==8) return (eight[b%4]-48);
}

bool isPsycho(ll k, ll b, ll p)
{
    ll n = trailingZeroes(k)*lastdigit(b,p);
    ll even,odd;
    even = odd = 0;
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
        }
    }
    if(n != 1)
        odd++;
    if(even>odd)
        return true;
    else
        return false;
}

int main()
{
    ll t,k,b,p;
    gl(t);
    while(t--)
    {
        gl(k); gl(b); gl(p);
        if( isPsycho(k,b,p) )
            cout<<"Psycho Number\n";
        else
            cout<<"Ordinary Number\n";
        //pn;
    }
}
