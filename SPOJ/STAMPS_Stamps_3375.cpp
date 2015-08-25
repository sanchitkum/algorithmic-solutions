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
    int t,friends,val;
    gi(t);
    ll total;
    FORE(j,1,t)
    {
        gl(total);
        gi(friends);
        vector <int> v;
        FOR(i,0,friends)
        {
            cin>>val;
            v.push_back(val);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ll sum = 0;
        int i = 0;
        while(sum < total && i<friends)
        {
            sum = sum + v[i];
            i++;
        }
        if(sum >= total)
        {
            cout<<"Scenario #"<<j<<":";pn;
            cout<<i;pn;pn;
        }
        else
        {
            cout<<"Scenario #"<<j<<":";pn;
            cout<<"impossible";pn;pn;
        }
    }
}
