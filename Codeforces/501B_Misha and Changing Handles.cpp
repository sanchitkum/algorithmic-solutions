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
    int q;
    gi(q);
    map <string,string> user;
    int cnt = 0;
    cin.ignore();
    while(q--)
    {
        string olds,news;
        olds.clear();
        news.clear();
        cin>>olds;
        cin>>news;
        if(user.empty())
        {
            user[olds] = news;
            cnt++;
        }
        else
        {
            int flag = 0;
            for( map<string,string>::iterator it = user.begin(); it != user.end(); ++it )
            {
                if (news == it->fs || news == it->sc)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                continue;
            for( map<string,string>::iterator it = user.begin(); it != user.end(); ++it )
            {
                if( olds == it->sc )
                {
                    user[it->fs] = news;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                continue;
            user[olds] = news;
            cnt++;
        }
    }
    pin(cnt);
    for( map<string,string>::iterator it = user.begin(); it != user.end(); ++it )
    {
        cout<<it->fs<<" "<<it->sc;pn;
    }
}
