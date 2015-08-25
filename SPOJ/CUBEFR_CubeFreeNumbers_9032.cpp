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
#define gl(n) cin>>n

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

//pair<bool, ll> pval(1,0);
//vector< pair<bool,ll> > v(1000010,pval);
vector<bool> cube(1000010,0);
vector<bool> v(1000010,1);
vector<ll> sum(1000010,0); //Stores the number of cube factor before the given number

void cubee()
{
    ll i = 2;
    while( i <= 101 )
    {
        cube[i*i*i] = 1;
        i++;
    }
}

void sieve()
{
     forup(i,1,1000001)
     {
         if(cube[i])
         {
            for(ll j = i; j <= 1000001; j = j+i)
            {
                 v[j] = false;
                 sum[j] = 1;
            }
         }
         sum[i] += sum[i-1];
     }
}

int main()
{
    cubee();
    sieve();
    ll t,n;
    gl(t);
    fore(i,1,t)
    {
        gl(n);
        if(v[n])
        {
            cout<<"Case "<<i<<": "<<n-sum[n];
            pn;
        }
        else
        {
            cout<<"Case "<<i<<": Not Cube Free";pn;
        }
    }
}
