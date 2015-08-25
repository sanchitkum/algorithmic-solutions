using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
//#define getmax(a,b) a>b?a:b
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#define pn printf("\n")
#define ps printf(" ")
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n

int main()
{
    int t;
    ll n;
    gi(t);
    while(t--)
    {
        gl(n);
        ll inc = 0;
        ll val = 1;
        ll i = 1;
        while(val < n)
        {
            inc += 4;
            val = val + inc;
            i++;
        }
        ll j = i;
        ll copy = i;
        int found = 0;
        while(j!=0)
        {
            if(val == n)
            {
                found = 1;
                break;
            }
            j--; i++;
            val--;
        }
        if(!found)
        {
            j = 1;
            i = i-2;
            while(i!=0)
            {
                if(val == n)
                {
                    found = 1;
                    break;
                }
                j++; i--;
                val--;
            }
        }
        if(!found)
        {
            i = 1;
            j = j-2;
            while(j!=0)
            {
                if(val == n)
                {
                    found = 1;
                    break;
                }
                j--; i++;
                val--;
            }
        }
        cout<<"TERM "<<n<<" IS "<<i<<"/"<<j;pn;
    }
}
