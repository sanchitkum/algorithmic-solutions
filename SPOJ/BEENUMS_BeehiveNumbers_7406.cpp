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

// https://codegeeksblog.wordpress.com/2013/06/01/spoj-beenums-beehive-numbers/

/*
Logic:

Equation:   a(n) = a(n-1) + 6(n-1)  // a(1) = 1
                 = a(n-2) + 6(n-2) + 6(n-1)
                 .
                 .
                 .
                 = a(1) + 6(1-1) + ... + 6(n-2) + 6(n-1)
                 = 1 + 6( 0 + 1 + ... + (n-1) )
                 = 1 + 6 ( (n-1)*n/2)
                 = 3*n*(n-1) + 1
*/

int main()
{
    ll n;
    while(true)
    {
        gl(n);
        if(n == -1)
            break;
        ll val = 0,i = 1;
        int flag = 0;
        while(val < n)
        {
            val = 3*i*(i-1) + 1;
            if(val == n)
            {
                flag = 1;
                break;
            }
            i++;
        }
        if(flag == 1)
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
}
