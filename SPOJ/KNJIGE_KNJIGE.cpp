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
    int n,val;
    gi(n);
    vi v;
    rep(i,n)
    {
        gi(val);
        v.pb(val);
    }
    int last = n;
    fordn(i,n-1,0)
    {
        if(v[i] == last)
            last--;
    }
    pin(last);
}

/*
Eg: -> Wrong Logic!
1 3 2 4 5
-> 3 steps as 4 and 5 in correct position from last
2 3 1 4 5
-> 1 step as 4 and 5 in correct postion from last and also 2 and 3 in correct position from start
2 3 1 5 4
-> For no in order, steps required is 'n', here 5 => Wrong Logic -> can be done in 4 steps!

Will Fail in

4 3 5 2 1
-> Answer should be 3, i will get 5 with the wrong logic
*/

/*
int main()
{
    int n,val;
    gi(n);
    vi v;
    v.pb(0);// To make it 1-based indexing
    rep(i,n)
    {
        gi(val);
        v.pb(val);
    }
    int i;
    // Calculate all books in correct position from the last
    dfordn(i,n,1)
    {
        if(v[i] != i)
            break;
    }
    int in_pos_last = n-i;
    //  cout<<in_pos_last;pn;
    // Calculate all books in correct position from the beginning, taking into consideration the above case
    int pos = i;
    while(v[i] != pos) // Point to correct i location for that particlar value
        i--;
    int in_pos_start = 0;
    dfordn(i,i,1)
    {
        if(v[i] != pos)
            break;
        pos--;
        in_pos_start++;
    }
    if(i != 0) // It did not reach the start, so they are not in order
        in_pos_start = 0;
    //cout<<in_pos_start;pn;
    cout<<(n-(in_pos_last+in_pos_start));pn;
}
*/
