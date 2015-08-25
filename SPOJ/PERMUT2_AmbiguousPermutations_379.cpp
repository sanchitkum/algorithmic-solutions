using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<map>

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
    while(true)
    {
        gl(n);
        if(n == 0)
            break;
        int arr[n+1];
        map <int,int> inverse;
        FORE(i,1,n)
        {
            cin>>arr[i];
            inverse[arr[i]] = i;
        }
        int flag = 0;
        FORE(i,1,n)
        {
            if(arr[i] != inverse[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<"not ambiguous\n";
        else
            cout<<"ambiguous\n";
    }
}
