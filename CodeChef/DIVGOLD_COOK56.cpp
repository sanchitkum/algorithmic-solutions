#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )

#define gi(n) scanf("%d",&n)
//#define gl(n) cin>>n
#define gl(n) scanf("%lld",&n)

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

#define matrix vector< vector<ll> >
//#define repVector(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); ++it )

#define INPFILE freopen("input.in","r",stdin)

int main()
{
    //INPFILE;
    int t,n;
    gi(t);
    string s;
    while(t--)
    {
        gi(n);
        cin.ignore();
        getline(cin,s);
        string s2 = s;
        sort(all(s2));
        if( s2 == s )
        {
            cout<<s;pn;
            continue;
        }
        s2 = s; // copy
        string res = s;
        char ch;
        //cout<<s2;pn;
        forup(i,0,n)
        {
            ch = s[i];
            forup(j,0,n)
            {
                if(i == j)
                    continue;
                s2.erase(i,1);
                s2.insert(j,1,ch);
                if(s2 < res)
                    res = s2;
                s2 = s;
            }
        }
        cout<<res;pn;
    }
}
