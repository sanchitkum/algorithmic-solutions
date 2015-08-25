using namespace std;

#include<iostream>
#include<math.h>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
#define getmax(a,b) a>b?a:b

int main()
{
    int n,sum;
    while(true)
    {
        sum = 0;
        cin>>n;
        if(n==0)
            break;
        cout<<n*(n+1)*((2*n)+1)/6<<'\n';
    }
}
