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

#define pin(x) printf("%d\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

int main()
{
    int n,m;
    gi(n);gi(m);
    char arr[n][m];
    rep(n)
    {
        forup(j,0,m)
        {
            arr[i][j] = '.';
        }
    }
    for(int i = 0; i<n; i=i+2)
    {
        forup(j,0,m)
        {
            arr[i][j] = '#';
        }
    }
    int flag = 1;
    for(int i = 1; i<n; i=i+2)
    {
        if(flag == 1)
            arr[i][m-1] = '#';
        else
            arr[i][0] = '#';
        flag = flag * -1;
    }
    rep(n)
    {
        forup(j,0,m)
        {
            cout<<arr[i][j];
        }
        pn;
    }
}
