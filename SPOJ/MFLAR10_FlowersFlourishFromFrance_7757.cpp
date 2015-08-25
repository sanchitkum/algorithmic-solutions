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
#define gl(n) cin>>n

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

int main()
{
    string s;
    while(true)
    {
        s.clear();
        getline(cin,s);
        if(s.length() == 0)
            continue;
        if(s[s.length()-1] == '*')
            break;
        int flag = 0;
        char ch;
        ll i = 0;
        while( i < s.length() && !isalpha(s[i]) ) // While the first character is not encountered
        {
            i++;
        }
        if(i == s.length())
            continue;
        ch = tolower(s[i]);  // Assign 'ch' the first character
        dforup(i,i,s.length())
        {
            while(i < s.length() && isalpha(s[i])) // Keep moving ahead until a space is encountered
            {
                i++;
            }
            if(i == s.length())
                break;
            while(i < s.length() && !isalpha(s[i])) // Keep moving ahead until the first character of new word is encountered
            {
                i++;
            }
            if(i == s.length())
                break;
            if(tolower(s[i]) != ch) // If this new character is not equal then, make flag 1 and break
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<"N\n";
        else
            cout<<"Y\n";
    }
}
