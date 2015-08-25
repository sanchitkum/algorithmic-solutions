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
#define MOD 1000000007

int main()
{
    int n,key,val,cnt = 0;
    gi(n);
    map <int,vi> mp;
    while(n--)
    {
        gi(key);
        int m;
        gi(m);
        rep(m)
        {
            gi(val);
            mp[key].pb(val);
        }
    }
    vi friends;
    for( map<int,vi>::iterator it = mp.begin(); it!= mp.end(); ++it)
    {
        for( vi::iterator vit = mp[it->fs].begin(); vit != mp[it->fs].end(); ++vit)
        {
            if(mp.count(*vit) == 0)
            {
                    vi::iterator findvar;
                    findvar = find(friends.begin(),friends.end(),*vit);
                    if(findvar == friends.end())
                    {
                        friends.pb(*vit);
                        cnt++;
                    }
            }
        }
    }
    pin(cnt);
}
