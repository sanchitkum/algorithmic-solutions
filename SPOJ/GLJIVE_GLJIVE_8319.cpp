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
/*  COMMENTED Part is the Correct Logic if we consider that Mario can start from Anywhere
// The problem statement is confusing. It has asked to consider only from the first point!
int main()
{
    vi v;
    int val;
    forup(i,0,10)
    {
        gi(val);
        v.pb(val);
    }
    int sumg = 0;
    int suml = 0;
    vi vres;
    int res,rval; //fres = final result
//**
    forup(i,0,10) // Starting from First take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) ) // Push it to a vector of closest results
        vres.pb(suml);
    else
        vres.pb(sumg);
//**
    sumg = suml = 0;
    forup(i,1,10) // Starting from Second take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    sumg = suml = 0;
    forup(i,2,10) // Starting from THIRD take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    sumg = suml = 0;
    forup(i,3,10) // Starting from Fourth take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    sumg = suml = 0;
    forup(i,4,10) // Starting from FIFTH take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    sumg = suml = 0;
    forup(i,5,10) // Starting from SIXTH take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    sumg = suml = 0;
    forup(i,6,10) // Starting from Seventh take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    sumg = suml = 0;
    forup(i,7,10) // Starting from Eight take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    sumg = suml = 0;
    forup(i,8,10) // Starting from NINTH take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    sumg = suml = 0;
    forup(i,9,10) // Starting from TENTH take the Sum
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }

    if((100-suml) < (sumg-100) )
        vres.pb(suml);
    else
        vres.pb(sumg);

//**
    res = vres[0];
    forup(i,1,10)
    {
        val = vres[i] - 100;
        rval = res - 100;
        if( absol(val) < absol(rval) )
            res = vres[i];
        else if( absol(val) == absol(rval) )
            res = max(res,vres[i]);
    }
    pin(res);
}
*/

// https://mukeshiiitm.wordpress.com/2011/05/20/spoj-gljive/
// Solution if it starts only from the FIRST Point

int main()
{
    vi v;
    int val;
    forup(i,0,10)
    {
        gi(val);
        v.pb(val);
    }
    int sumg = 0;
    int suml = 0;
    forup(i,0,10)
    {
        sumg += v[i];
        if(sumg >= 100)
        {
            suml = sumg - v[i];
            break;
        }
    }
    if((100-suml) < (sumg-100) )
        pin(suml);
    else
        pin(sumg);
}
