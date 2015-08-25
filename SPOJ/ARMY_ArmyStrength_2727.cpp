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
    int t;
    gi(t);
    ll ng,nm,val;
    while(t--)
    {
        pn;
        gl(ng);
        gl(nm);
        vector <ll> vg,vm;
        FOR(i,0,ng)
        {
            cin>>val;
            vg.push_back(val);
        }
        FOR(i,0,nm)
        {
            cin>>val;
            vm.push_back(val);
        }
        sort(vg.begin(),vg.end());
        sort(vm.begin(),vm.end());
        ll i = 0;
        ll j = 0;
        while(i < ng && j < nm)
        {
            if(vg[i] < vm[j])
                i++;
            else if(vg[i] > vm[j])
                j++;
            else
                j++;
        }
        if(i == ng && j != nm)
            {cout<<"MechaGodzilla";pn;}
        else if (j == nm && i != ng)
            {cout<<"Godzilla";pn;}
        else
            {cout<<"uncertain";pn;}
    }
}
