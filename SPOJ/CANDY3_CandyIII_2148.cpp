using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

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
    ll t,n,sum,val;
    gl(t);
    while(t--)
    {
        pn;
        gl(n);
        sum = 0;
        FOR(i,0,n)
        {
            gl(val);
            sum += val;
            if(sum >= n)
                sum %= n;
        }
        if(sum == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
