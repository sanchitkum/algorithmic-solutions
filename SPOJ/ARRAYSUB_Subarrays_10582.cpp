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
    ll n;
    gl(n);
    vll v;
    ll val;
    rep(n)
    {
        gl(val);
        v.pb(val);
    }
    ll k;
    gl(k);
    ll maxpos;
    ll maxval = -1;
    forup(i,0,k) // For the first 'k' elements
    {
        if(v[i] >= maxval)
        {
            maxval = v[i];
            maxpos = i;
        }
    }
    cout<<maxval;ps; // Find and print the max element

    forup(i,k,n) // For all the next elements from k
    {
        if(v[i] >= maxval) // If the the value of element is greater than maxval then assign the maxval its new value
        {
            maxval = v[i];
            maxpos = i;
        }

        if( (i-maxpos) >= k) // If the "position" of maxval is not in the range of k, then update the new maxval // Meeting condition is "==k"
        {
            maxval = -1; // Make maxval the unachieavble number, so that new maxval can be found
            fore(j,maxpos+1,i) // fore(j,maxpos+1,maxpos+k) // Since at meeting condition (i-maxpos) == k
            {
                if(v[j] > maxval)
                {
                    maxval = v[j];
                    maxpos = j;
                }
            }
        }
        cout<<maxval;ps;
    }
    pn;
    /* NAIVE
    for( ll i = 0; i < n ; i++ )
    {
        maxval = max(maxval,v[i]);
        cnt++;
        if(cnt == k)
        {
            cout<<maxval;ps;
            cnt = 0;
            maxval = -1;
            i = i-(k-1);
        }
    }
    pn;
    */
}
