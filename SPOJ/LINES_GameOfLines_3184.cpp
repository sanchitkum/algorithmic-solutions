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
#define gl(n) cin>>n

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

int gcd(int a, int b)
{
    if (b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int n;
    while(true)
    {
        gi(n);
        if(n == 0)
            break;
        vector< pii > v;
        //v.clear();
        pii val;
        rep(n)
        {
            gi(val.fs); gi(val.sc);
            v.pb(val);
        }
        set< pii > slope;
        //slope.clear();
        rep(n)
        {
            forup(j,i+1,n)
            {
                val.fs = v[i].sc - v[j].sc;
                val.sc = v[i].fs - v[j].fs;
                int gcdval = __gcd(val.fs,val.sc); // __gcd is an inbuilt function
                val.fs /= gcdval;
                val.sc /= gcdval;
                if (val.sc < 0) // For negative cases to ensure that denominator is always positive, multiply both with -1
                {
                    val.fs = val.fs * -1;
                    val.sc = val.sc * -1;
                }
                slope.insert(val);
            }
        }
        cout<<slope.size();pn;
    }
}
