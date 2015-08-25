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

/*
Logic:
Given a cubic equation : x^3 + ax^2 + bx + c = 0
We need to find the square of distance, where roots are the coordinates
Now roots are p,q,r
So, we need to find p^2 + q^2 + r^2

Now,
(p+q+r)^2 = p^2 + q^2 + r^2 + 2(pq + qr + pr)

Then we know,
p+q+r = -a ; and
pq + qr + pr = b

Therefore,
p^2 + q^2 + r^2 = (-a)^2 - 2(b);
Square of distance = a^2 - 2(b);
*/

int main()
{
    int t;
    gi(t);
    ll a,b,c;
    while(t--)
    {
        gl(a); gl(b); gl(c);
        ll res = (a*a) - (2*b);
        pln(res);
    }
}
