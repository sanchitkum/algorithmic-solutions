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
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )

#define gi(n) scanf("%d",&n)
#define gl(n) cin>>n

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define MOD 1000000007

/*
int main()
{
    while(true)
    {
        int n1,n2;
        int val;
        vi v1,v2;
        ll sum1,sum2,sum;
        gi(n1);
        if(n1 == 0)
            break;
        rep(n1)
        {
            gi(val);
            v1.pb(val);
        }
        gi(n2);
        rep(n2)
        {
            gi(val);
            v2.pb(val);
        }
        int i,j;
        i = j = 0;
        sum = sum1 = sum2 = 0;
        while(i<n1 && j<n2)
        {
            //sum1 = sum2 = 0;
            do
            {
                while(v1[i] < v2[j] && i<n1 && j<n2)
                {
                    sum1 = sum1 + v1[i++];
                }
                while(v2[j] < v1[i] && j<n2 && i<n1)
                {
                    sum2 = sum2 + v2[j++];
                }
            }while(v1[i] != v2[j] && i<n1 && j<n2);
            if(v1[i] == v2[j])
            {
                //cout<<sum;pn;
                sum = sum + max(sum1,sum2);
                //cout<<sum;pn;
                sum = sum + v1[i];
                //cout<<sum;pn;
                sum1 = sum2 = 0;
                i++;j++;
            }
        }
        if(i != n1 || j!= n2)
        {
            while(i<n1)
            {
                sum1 = sum1 + v1[i++];
            }
            //cout<<sum1;pn;
            while(j<n2)
            {
                sum2 = sum2 + v2[j++];
            }
            //cout<<sum2;pn;
            sum = sum + max(sum1,sum2);
        }
        pln(sum);
    }
}
*/

///*
int main()
{
    while(true)
    {
        ll n1,n2,res = 0;
        ll sum1,sum2;
        set<int> s1,s2;
        int temp;
        gl(n1);
        if(n1 == 0)
            break;
        rep(n1)
        {
            gi(temp);
            s1.insert(temp);
        }
        gl(n2);
        rep(n2)
        {
            gi(temp);
            s2.insert(temp);
        }
        set<int>::iterator it = s1.begin(); // iterator over the s1 set
        set<int>::iterator lits1 = s1.begin(); // last iterator position for s1,
        set<int>::iterator lits2 = s2.begin(); // to help know the last intersection point;
        set<int>::iterator itfin; // iterator that points to the intersection point found;
        sum1 = sum2 = 0;
        while(it != s1.end())
        {
            itfin = s2.find(*it);
            if(itfin == s2.end())
            {
                it++;
                continue;
            }
            else
            {
                sum1 = sum2 = 0;
                set<int>::iterator its1;
                set<int>::iterator its2;
                for(its1 = lits1; its1 != it; ++its1)
                {
                    sum1 = sum1 + *its1;
                }
                for(its2 = lits2; its2 != itfin; ++its2)
                {
                    sum2 = sum2 + *its2;
                }
                if(sum1>sum2)
                    res += sum1;
                else
                    res += sum2;
                res += *it;
                lits1 = ++its1;
                lits2 = ++its2;
                ++it;
                sum1 = sum2 = 0;
            }
        }
        while(lits1 != s1.end())
        {
            sum1 += *lits1;
            ++lits1;
        }
        while(lits2 != s2.end())
        {
            sum2 += *lits2;
            ++lits2;
        }
        if(sum1>sum2)
            res += sum1;
        else
            res += sum2;
        pln(res);
    }
}
//*/
