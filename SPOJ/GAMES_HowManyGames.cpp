#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>=b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>=b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define gi(n) scanf("%d",&n);
#define gl(n) scanf("%lld",&n);
#define pin(x) printf("%d\n",x);
#define pln(x) printf("%lld\n",x);
#define pn printf("\n");
#define ps printf(" ");

#define fs first
#define sc second
#define pb push_back

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

ll StringToDecimal(string s)
{
   ll res = 0;
   forup(i,0,s.length())
   {
       if(s[i] == '.')
        continue; // Ignore the '.', if it exists
       res = (res*10) + (s[i]-48);
   }
   return res;
}

int main()
{
    int t;
    gi(t);
    cin.ignore();
    string s;
    while(t--)
    {
        getline(cin,s);
        ll avg = StringToDecimal(s);
        int digits = s.find('.');
        if (digits == -1) // No decimal point
            {pin(1); continue;} // Can be done in one game
        digits = (s.length()-1)-digits;
        ll den = pow(10,digits);
        ll hcf = __gcd(avg,den);
        while( hcf != 1)
        {
            avg = avg / hcf;
            den = den / hcf;
            hcf = __gcd(avg,den);
        }
        pln(den);
    }
}
