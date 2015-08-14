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
#define MOD 1000000007

int main()
{
    int t;
    gi(t);
    ll n,k;
    while(t--)
    {
        gl(n); gl(k);
        vector<ll> vk;
        vector<ll> vksum;
        ll val;
        ll sumofk = 0;
        rep(k)
        {
            gl(val);
            vk.pb(val);
        }
        sort(all(vk));
        rep(k)
        {
            vksum.pb(sumofk);
            sumofk = sumofk + vk[i];
        }
        int flag = 0;
        forup(i,0,k)
        {
            ll sumk = (vk[i]-1)*vk[i]/2;
            sumk = sumk - vksum[i];
            if(sumk >= vk[i])
                continue;
            else
            {
                if(vk[i]%2 == 0)
                {
                    cout<<"Mom\n";
                    flag = 1;
                    break;
                }
                else
                {
                    cout<<"Chef\n";
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            continue;
        ll sumn = n*(n+1)/2;
        if( (sumn-sumofk)%2 == 0 )
        {
            cout<<"Chef\n";
            continue;
        }
        else
        {
            cout<<"Mom\n";
            continue;
        }
    }
}
