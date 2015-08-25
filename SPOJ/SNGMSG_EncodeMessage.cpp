#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>=b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>=b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

char convertToMsg(char ch, int key_val)
{
    if(ch-key_val >= 97)
        return ch-key_val;
    ch = ch - 97;
    key_val = key_val - ch;
    //At this point my 'ch' has reached to 'a' position and needs to furthur go backward by key_val positions;
    ch = 122 - key_val + 1;
    return ch;
}

int main()
{
    //INPFILE;
    int t;
    gi(t);
    cin.ignore();
    string key,encoded;
    while(t--)
    {
        getline(cin,key);
        getline(cin,encoded);
        int direction = 1; // 1-> Right ; 0-> Left
        int i = 0; // Points to the encoded msg;
        int j = 0; // Points to the key;
        while(i<encoded.length())
        {
            char ch;
            if(direction == 1)
            {
                ch = convertToMsg(encoded[i],key[j++]-48);
                if(j == key.length())
                    {j = key.length()-1; direction = 0;}
            }
            else
            {
                ch = convertToMsg(encoded[i],key[j--]-48);
                if(j == -1)
                    {j = 0; direction = 1;}
            }
            printf("%c",ch);
            i++;
        }
        pn;
    }
}
