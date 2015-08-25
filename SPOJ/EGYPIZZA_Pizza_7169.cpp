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
    ll n;
    gl(n);
    ll cnt1,cnt2,cnt3,pizza;
    pizza = cnt1 = cnt2 = cnt3 = 0;
    string s;
    cin.ignore();
    rep(n)
    {
        cin>>s;
        if(s == "1/2")
            cnt1++;
        else if (s == "1/4")
            cnt2++;
        else if (s == "3/4")
            cnt3++;
    }
    pizza += cnt1/2; // Add the no of pizzas considering half each half pizzas
    if(cnt1%2 == 1) // If one slice of half is left
    {
        pizza++;  // Add another pizza
        cnt2 = cnt2 - 2; // The rest half can be divided into two 1/4 so decrement the 1/4 requirememnt
    }
    pizza += cnt3; // Each 3/4 slice requires a complete pizza to be ordered.
    cnt2 = cnt2 - cnt3; // The remaining 1/4 from each 3/4 can be used to give to 1/4 people
    if(cnt2 > 0) // If still some 1/4 people are left
    {
        pizza += cnt2/4; // Add the required pizzas for 1/4 slice people
        if(cnt2%4) // If some remainder, i.e is 1 or 2 or 3 people are left
            pizza++; // Add one more pizza for them
    }
    pizza++; // This is for the guy who wants one complete pizza
    pln(pizza);
}
