using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<map>
#include<math.h>

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
    ll n;
    gl(n);
    ll val = 1;
    ll i = 0;
    while(val < n)
    {
        val = pow(2,i);
        i++;
    }
    if (val == n)
        cout<<"TAK";
    else
        cout<<"NIE";
}
