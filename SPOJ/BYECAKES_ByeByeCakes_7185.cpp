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
    int e,f,s,m,ee,ff,ss,mm;
    int re,rf,rs,rm;
    while(true)
    {
        cin>>e>>f>>s>>m>>ee>>ff>>ss>>mm;
        if( e == -1 && f == -1 && s == -1 && m == -1 && ee == -1 && ff == -1 && ss == -1 && mm == -1)
            break;
        int req = ceil((double)e/ee);
        int val = ceil((double)f/ff);
        req = max(req,val);
        val = ceil((double)s/ss);
        req = max(req,val);
        val = ceil((double)m/mm);
        req = max(req,val);
        re = (req*ee) - e;
        rf = (req*ff) - f;
        rs = (req*ss) - s;
        rm = (req*mm) - m;
        cout<<re<<" "<<rf<<" "<<rs<<" "<<rm;
        pn;
    }
}
