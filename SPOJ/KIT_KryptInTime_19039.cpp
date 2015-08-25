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

int main()
{
    int n,val;
    gi(n);
    vi v;
    rep(n)
    {
        gi(val);
        v.pb(val);
    }
    char str[100000];
    cin.ignore();
    cin.getline(str,100000,'-1');
    int i = 0; // for string
    int j = 0; // for vector
    while( str[i] != '-' )
    {
        if( isalpha(str[i]) )
        {
            if(str[i] + v[j] <= 122)
                cout<<(char)(str[i]+v[j]);
            else
                cout<<(char)(str[i]+v[j]-26);
            i++;j++;
            if(j == n)
                j=0;
        }
        else
        {
            pn;
            i++;
            continue;
        }
    }
}
