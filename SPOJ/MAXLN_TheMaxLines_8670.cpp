//https://www.quora.com/How-do-I-solve-this-question-SPOJ-com-Problem-MAXLN

#include<iostream>
#include<vector>
#include<map>
#include<set>
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

//https://www.quora.com/How-do-I-solve-this-question-SPOJ-com-Problem-MAXLN

int main()
{
    int t;
    gi(t);
    fore(i,1,t)
    {
        ll r;
        gl(r);
        /* Maximum value of a quadratic equation ax^2+bx+c = 0 is (-b/2a)
        ab^2 = 4*r^2 - ac^2
        s = -ac^2 + ac + 4*r^2
        To maximize, differntiate and put to 0
        val of ac for s to be max (-b/2a) i.e. 1/2
        */
        double s = (4*r*r) + 0.25;
        cout<<"Case "<<i<<": ";
        printf("%0.2f",s);pn;
    }
}
