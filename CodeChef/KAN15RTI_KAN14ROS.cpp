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
#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11

#define INPFILE freopen("input.in","r",stdin)

void decimal_to_binary(ll k, string &b)
{
    int rem;
    while(k)
    {
        rem = k%2;
        b.pb(rem+48);
        k /= 2;
    }
    reverse(all(b));
}

string add_binary(string l, string b)
{
    reverse(all(l));
    reverse(all(b));
    string res;
    int len = min(l.length(),b.length());
    int temp;
    int carry = 0;
    int rem;
    forup(i,0,len)
    {
        temp = carry + l[i] + b[i] - 96;
        carry = temp/2;
        rem = temp%2;
        res.pb(rem+48);
    }
    if( (l.length() == b.length()) && carry )
            res.pb(carry+48);
    else if(l.length() < b.length())
    {
        forup(i,len,b.length())
        {
            temp = carry + b[i] - 48;
            carry = temp/2;
            rem = temp%2;
            res.pb(rem+48);
        }
        if(carry)
            res.pb(carry+48);
    }
    else
    {
        forup(i,len,l.length())
        {
            temp = carry + l[i] - 48;
            carry = temp/2;
            rem = temp%2;
            res.pb(rem+48);
        }
        if(carry)
            res.pb(carry+48);
    }
    reverse(all(res));
    return res;
}

int main()
{
    //INPFILE;
    int t;
    gi(t);
    cin.ignore();
    while(t--)
    {
        string l;
        ll k;
        getline(cin,l);
        gl(k);
        cin.ignore();
        string b;
        decimal_to_binary(k,b);
        string res = add_binary(l,b);
        cout<<res;pn;
    }
}
