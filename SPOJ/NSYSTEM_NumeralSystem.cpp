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
#define gi(n) scanf("%d",&n)
#define gl(n) cin>>n
#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

int convertToInt(string s)
{
    int total = 0;
    int constant = 1;
    forup(i,0,s.length())
    {
        switch(s[i])
        {
        case 'm':
            total += constant * 1000;
            constant = 1;
            break;
        case 'c':
            total += constant * 100;
            constant = 1;
            break;
        case 'x':
            total += constant * 10;
            constant = 1;
            break;
        case 'i':
            total += constant;
            constant = 1;
            break;
        default:
            constant = s[i] - 48;
        }
    }
    return total;
}

void convertToMCXI(int v)
{
    int a,b,c,d;
    a = (v/1000) % 10;
    b = (v/100) % 10;
    c = (v/10) % 10;
    d = v % 10;
    if(a == 1)
        cout<<"m";
    else if(a != 0)
        cout<<a<<"m";
    if(b == 1)
        cout<<"c";
    else if(b != 0)
        cout<<b<<"c";
    if(c == 1)
        cout<<"x";
    else if(c != 0)
        cout<<c<<"x";
    if(d == 1)
        cout<<"i";
    else if(d != 0)
        cout<<d<<"i";
    pn;
}

int main()
{
    //INPFILE;
    int n;
    gi(n);
    cin.ignore();
    string s1,s2,res;
    int v1,v2,v;
    while(n--)
    {
        cin>>s1>>s2;
        v1 = convertToInt(s1);
        v2 = convertToInt(s2);
        v = v1 + v2;
        convertToMCXI(v);
    }
}
