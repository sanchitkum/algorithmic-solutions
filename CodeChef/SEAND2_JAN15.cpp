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
#define MOD 1000000007

int main()
{
    int t;
    gi(t);
    cin.ignore();
    while(t--)
    {
        string a;
        a.clear();
        getline(cin,a);
        int n,val;
        gi(n);
        vi b;
        rep(n)
        {
            gi(val);
            b.pb(val);
        }
        sort(all(b));
        sort(all(a));
        reverse(all(a));
        if(b[n-1] >= 1000000)
        {
            if(a.length() >= 6)
                sort(a.end()-6,a.end());
            cout<<a;pn;
            cin.ignore();
            continue;
        }
        else if(b[n-1] >= 100000)
        {
            if(a.length() >= 5)
                sort(a.end()-5,a.end());
            cout<<a;pn;
            cin.ignore();
            continue;
        }
        else if(b[n-1] >= 10000)
        {
            if(a.length() >= 4)
                sort(a.end()-4,a.end());
            cout<<a;pn;
            cin.ignore();
            continue;
        }
        else if(b[n-1] >= 1000)
        {
            if(a.length() >= 3)
                sort(a.end()-3,a.end());
            cout<<a;pn;
            cin.ignore();
            continue;
        }
        else if(b[n-1] >= 100)
        {
            if(a.length() >= 2)
                sort(a.end()-2,a.end());
            cout<<a;pn;
            cin.ignore();
            continue;
        }
        else if(b[n-1] >= 10)
        {
            if(a.length() >= 1)
                sort(a.end()-1,a.end());
            cout<<a;pn;
            cin.ignore();
            continue;
        }
        else
        {
            cout<<a;pn;
            cin.ignore();
            continue;
        }
    }
}
