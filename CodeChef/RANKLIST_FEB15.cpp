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
#include<cctype>

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
Logic: 5 numbers implies atleast -> 1 1 1 1 1
Now values of sum will range from 5 to 15
Sum -> Possible values -> operations needed to make an ideal ranklist
5  -> 1 1 1 1 1 -> 4
6  -> 1 1 1 1 2 -> 3
7  -> 1 1 1 2 2 -> 3
8  -> 1 1 1 2 3 -> 2
9  -> 1 1 2 2 3 -> 2
10 -> 1 1 2 3 3 -> 2
11 -> 1 1 2 3 4 -> 1
12 -> 1 2 2 3 4 -> 1
13 -> 1 2 3 3 4 -> 1
14 -> 1 2 3 4 4 -> 1
15 -> 1 2 3 4 5 -> 0
*/

int main()
{
    int t;
    gi(t);
    ll n,s;
    while(t--)
    {
        gl(n); gl(s);
        ll cnt = n;
        ll sum = n;
        ll i = 1;
        while(sum <= s)
        {
            sum = sum + i;
            i++;
            cnt--;
        }
        pln(cnt);
    }
}
