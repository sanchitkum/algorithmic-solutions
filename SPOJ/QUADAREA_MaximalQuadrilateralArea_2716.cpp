//http://en.wikipedia.org/wiki/Brahmagupta%27s_formula

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

//http://en.wikipedia.org/wiki/Brahmagupta%27s_formula
/*
Brahmagupta's formula gives the area A of a cyclic quadrilateral whose sides have lengths a, b, c, d as
A = sqrt{(s-a)(s-b)(s-c)(s-d)}
where s, the semiperimeter, is defined to be
s = (a+b+c+d)/2.
*/
int main()
{
    int t;
    double a,b,c,d;
    gi(t);
    while(t--)
    {
        cin>>a>>b>>c>>d;
        double area,s;
        s = (a+b+c+d)/2;
        area = sqrt( (s-a) * (s-b) );
        area *= sqrt ( (s-c) * (s-d) );
        printf("%.2f\n",area);
    }
}
