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
#define gl(n) scanf("%lld",&n)

#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

int main()
{
    int t;
    gi(t);
    cin.ignore();
    string str;
    while(t--)
    {
        getline(cin,str);
        map<char,int> m;
        rep(str.length())
        {
            //cout<<m.count(str[i]);
            if(m.count(str[i]))
                m[str[i]]++;
            else
                m[str[i]] = 1;
        }
        int sum = 0;
        map<char,int>::iterator it,it2;
        int flag = 0;
        for(it = m.begin(); it != m.end(); ++it)
        {
            sum = 0;
            for(it2 = m.begin(); it2!= m.end(); ++it2)
            {
                if(it == it2)
                    continue;
                sum = sum+ it2->sc;
            }
            if(sum == it->sc)
            {
                cout<<"YES\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout<<"NO\n";
    }
}
