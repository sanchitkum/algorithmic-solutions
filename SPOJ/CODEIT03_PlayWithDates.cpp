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
Logic:
https://www.quora.com/How-does-Tomohiko-Sakamotos-Algorithm-work
http://stackoverflow.com/questions/6385190/correctness-of-sakamotos-algorithm-to-find-the-day-of-week/6385934#6385934
http://discuss.codechef.com/questions/62210/how-does-tomohiko-sakamotos-algorithm-work-need-details-explanation?page=1#67404
*/

int dow(int d, int m, int y)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m<3;
    return (y + (y/4) - (y/100) + (y/400) + t[m-1] + d)%7;
}

int main()
{
    string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int t;
    gi(t);
    int dd,mm,yy;
    while(t--)
    {
        gi(dd);gi(mm);gi(yy);
        int day = dow(dd,mm,yy);
        cout<<days[day];pn;
    }
}
