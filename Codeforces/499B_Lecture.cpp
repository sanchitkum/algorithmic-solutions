using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

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
    int n,m;
    cin>>n>>m;
    vector< pair<string,string> > v;
    pair <string,string> lang;
    FOR(i,0,m)
    {
        cin>>lang.first;
        cin>>lang.second;
        v.push_back(lang);
    }
    string str[n];
    FOR(i,0,n)
        cin>>str[i];
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            if(v[j].first == str[i] || v[j].second == str[i])
            {
                if( (v[j].first).length() <= (v[j].second).length() )
                    {
                        cout<<v[j].first;
                        if(i<n-1)
                            ps;
                    }
                else
                    {
                        cout<<v[j].second;
                        if(i<n-1)
                            ps;
                    }
            }
        }
    }
}
