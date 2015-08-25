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

int main()
{
    int g,b;
    while(true)
    {
        gi(g);gi(b);
        if(g == -1 && b == -1)
            break;
        int blankspace = min(g,b);
        int group = max(g,b);
        if( group%(blankspace+1) )
           cout<<( group/(blankspace+1) )+1;
        else
            cout<<group/(blankspace+1);
        pn;
        /*
        int small = min(g,b);
        vi v;
        v.pb(max(g,b));
        while(small--)
        {
            vi::iterator maxele = max_element(all(v));
            int val = *maxele;
            v.pb( val / 2);
            v.pb( val - val / 2);
            maxele = find(all(v),val);
            v.erase(maxele);
        }
        cout<<*max_element(all(v));pn;
        */
    }
}
