using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
#define getmax(a,b) a>b?a:b

int main()
{
    int n;
    ll cnt = 0;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(i*j <= n)
                cnt++;
            else
                break;
        }
    }
    cout<<cnt;
}
