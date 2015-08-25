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

/*
Solution:
Link: https://www.quora.com/How-do-I-solve-the-problem-SPOJ-SPEED
HCF/LCM: http://www.indiabix.com/aptitude/problems-on-hcf-and-lcm/formulas
*/

int main()
{
    //INPFILE;
    int t,s1,s2;
    gi(t);
    while(t--)
    {
        gi(s1); gi(s2);
        ll temp1 = s1-s2;
        temp1 = absol(temp1);
        ll temp2 = __gcd(s1,s2);
        temp2 = absol(temp2);
        ll res = temp1/temp2;
        pln(res);
    }
}
