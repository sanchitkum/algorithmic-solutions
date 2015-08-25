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
#define gi(n) scanf("%d",&n)
#define gl(n) cin>>n
#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back

#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11
#define INPFILE freopen("input.in","r",stdin)

int main()
{
    //INPFILE;
    int t,n,cnt;
    gi(t);
    while(t--)
    {
        cnt = 0;
        gi(n);
        vector< pii > time;
        pii pval;
        rep(i,n)
        {
            gi(pval.sc); gi(pval.fs); // End time is in "first" // For easier sorting of pair according to end time
            time.pb(pval);
        }
        sort(all(time));
        int last_time = 0;
        //'fs' is end time, 'sc' is start time
        forup(i,0,n)
        {
            if(time[i].sc >= last_time) // If start time is greater or equal to last time
            {
                cnt++;
                last_time = time[i].fs; // Make last time as the end time of this particular job;
            }
        }
        pin(cnt);
    }
}
