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

#define pin(x) printf("%d\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

int main()
{
    char s[110],t[110];
    cin>>s;
    cin>>t;
    int len = strlen(s);
    int i;
    dforup(i,0,len)
    {
        if(s[i]!=t[i])
            break;
    }
    if((t[i] - s[i]) > 1)
    {
        s[i] = s[i] + 1;
        cout<<s;pn;
        return 0;
    }
    i++;
    while(s[i] == 'z' && t[i] == 'a' && i<len)
    {
        i++;
    }
    //cout<<i;pn;
    if(i == len)
        cout<<"No such string\n";
    else
    {
        if(s[i] == 'z')
        {
            while(s[i] == 'z')
            {
                s[i] = 'a';
                i--;
            }
            s[i] += 1;
        }
        else
        {
            s[i] += 1;
        }
        cout<<s;pn;
    }
}
