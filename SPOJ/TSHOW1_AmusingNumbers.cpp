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
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
//#define gl(n) cin>>n
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
//#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

/*
--  -> k  -> Binary Digits -> Position
  5 -> 1  -> 0   -> 0
  6 -> 2  -> 1   -> 1
 55 -> 3  -> 00  -> 0
 56 -> 4  -> 01  -> 1
 65 -> 5  -> 10  -> 2
 66 -> 6  -> 11  -> 3
555 -> 7  -> 000 -> 0
556 -> 8  -> 001 -> 1
565 -> 9  -> 010 -> 2
566 -> 10 -> 011 -> 3
655 -> 11 -> 100 -> 4
656 -> 12 -> 101 -> 5
665 -> 13 -> 110 -> 6
666 -> 14 -> 111 -> 7
*/

int main()
{
    ll t,k;
    gl(t);
    int digits;
    ll pos;
    while(t--)
    {
        gl(k);
        digits = log2(k+1); // No of digits in the given position
        pos = k - (pow(2,digits) - 1); // The position such that digits are known
        vi sequence;
        int digits_copy = digits;
        while(digits)
        {
            if(pos&1)
                sequence.pb(6);
            else
                sequence.pb(5);
            pos = pos>>1;
            digits--;
        }
        fordn(i,digits_copy-1,0)
            cout<<sequence[i];
        pn;
    }
}
