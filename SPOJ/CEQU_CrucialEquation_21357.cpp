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

int gcd(int a, int b)
{
    if (b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int t,a,b,c;
    gi(t);
    fore(i,1,t)
    {
        /* Wrong Logic - Fails in case of 7 5 3, i.e when division becomes zero
        gi(a); gi(b); gi(c);
        int q1 = c/a;
        int q2 = c/b;
        if( (c-(q1*a))%b == 0 || (c-(q2*b))%a == 0 )
        {
            cout<<"Case "<<i<<": Yes\n";
            continue;
        }
        q1 = c/(-a);
        cout<<q1;pn;
        q2 = c/(-b);
        cout<<q2;pn;
        if( (c-(q1*a))%b == 0 || (c-(q2*b))%a == 0 )
        {
            cout<<"Case "<<i<<": Yes\n";
            continue;
        }
        cout<<"Case "<<i<<": No\n";
        */
        gi(a); gi(b); gi(c);
        int gcdval = gcd(a,b);
        if(c%gcdval == 0)
            cout<<"Case "<<i<<": Yes\n";
        else
            cout<<"Case "<<i<<": No\n";
    }
}
