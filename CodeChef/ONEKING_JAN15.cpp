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

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
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
#define MOD 1000000007

int main()
{
    int t;
    gi(t);
    int n,i;
    while(t--)
    {
        gi(n);
        vector< pii > v;
        pii val;
        drep(i,n)
        {
            cin>>val.fs>>val.sc;
            v.pb(val);
        }
        sort(all(v));
        int cnt = 0;
        drep(i,n)
        {
            int bound = v[i].sc;
            while( i+1<n && v[i+1].fs <= bound )
            {
                if(v[i+1].sc < bound)
                    bound = v[i+1].sc;
                i++;
            }
            cnt++;
        }
        pin(cnt);
    }
}
