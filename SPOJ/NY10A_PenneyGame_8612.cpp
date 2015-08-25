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
    ll n;
    string str,temp;
    while(t--)
    {
        gl(n);
        cin.ignore();
        getline(cin,str);
        int ttt,tth,tht,thh,htt,hth,hht,hhh;
        ttt = tth = tht = thh = htt = hth = hht = hhh = 0;
        fore(i,0,37)
        {
            temp = str.substr(i,3);
            if(temp == "TTT")
                ttt++;
            else if(temp == "TTH")
                tth++;
            else if(temp == "THT")
                tht++;
            else if(temp == "THH")
                thh++;
            else if(temp == "HTT")
                htt++;
            else if(temp == "HTH")
                hth++;
            else if(temp == "HHT")
                hht++;
            else if(temp == "HHH")
                hhh++;
        }
        cout<<n;ps;
        cout<<ttt;ps;cout<<tth;ps;cout<<tht;ps;cout<<thh;ps;cout<<htt;ps;cout<<hth;ps;cout<<hht;ps;cout<<hhh;ps;
        pn;
    }
}
