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
0 3 6 7
3 0 5 6
6 5 0 9
7 6 9 0

a+b = 3             b+c = 5         c+d = 9
a+c = 6             b+d = 6
a+d = 7

3a+(b+c+d)=3+6+7    2b+(c+d)=5+6    (c+d)
*/


ll mat[1010][1010]; // 1 - based indexing
ll res[1010] = {0}; // 1 - based indexing

int main()
{
    //INPFILE;
    int n;
    gi(n);
    fore(i,1,n)
        fore(j,1,n)
            gl(mat[i][j]);
    ll div = 2;
    if(n == 2)
        res[1] = res[2] = mat[1][2]/div;
    else
    {
        ll i,sum;
        ll reverse_sum = mat[n-1][n]; //Total sum from back side of the result array, initially take it as (n-1)+n;
        while( (n-div) >= 1 )
        {
            i = n-div;
            sum = 0;
            fore(j,i,n)
                sum += mat[i][j];
            res[n-div] = (sum - reverse_sum)/div;
            reverse_sum += res[n-div];
            div++;
        }
        res[n-1] = mat[1][n-1] - res[1]; // a+c = 6
        res[n] =  mat[1][n] - res[1]; // a+d = 7
    }
    fore(i,1,n)
        printf("%d ",res[i]);
}
