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
    string s,t;
    getline(cin,s);
    getline(cin,t);
    map<char,int> ms,mt;
    rep(s.length())
    {
        if(ms.count(s[i]) == 0)
            ms[s[i]] = 1;
        else
            ms[s[i]]++;
    }
    rep(t.length())
    {
        if(mt.count(t[i]) == 0)
            mt[t[i]] = 1;
        else
            mt[t[i]]++;
    }
    //cout<<"HERE";
    ll yay = 0;
    ll whoops = 0;
    for(map<char,int>::iterator it = ms.begin(); it != ms.end(); ++it) // Handle all that exists for YAY
    {
        char ch = it->fs;
        if(mt.count(ch))
        {
            if(ms[ch] > mt[ch])
            {
                yay = yay + mt[ch];
                ms[ch] = ms[ch] - mt[ch];
                mt[ch] = 0;
                //mt.erase(ch);
            }
            else if(ms[ch] < mt[ch])
            {
                yay = yay + ms[ch];
                mt[ch] = mt[ch] - ms[ch];
                ms[ch] = 0;
                //ms.erase(ch);
            }
            else
            {
                yay += ms[ch];
                mt[ch] = 0;
                ms[ch] = 0;
                //mt.erase(ch);
                //ms.erase(ch);
            }
        }
    }

    for(map<char,int>::iterator it = ms.begin(); it != ms.end(); ++it) // Handle all that does not exist for WHOOPS
    {
        //cout<<"Inside";
        char ch = it->fs;
        char chor = ch;
        if(isupper(ch))
            ch = tolower(ch);
        else
            ch = toupper(ch);
        if(ms[chor] == 0)
            continue;
        if(mt.count(ch))
        {
            if(mt[ch] == 0)
                continue;
            if(ms[chor] > mt[ch])
            {
                whoops = whoops + mt[ch];
            }
            else if(ms[chor] < mt[ch])
            {
                whoops = whoops + ms[chor];
            }
            else
            {
                whoops = whoops + ms[chor];
            }
        }
        //cout<<whoops;pn;
    }
    cout<<yay<<" "<<whoops<<endl;
}
