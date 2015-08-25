using namespace std;

#include<iostream>
#include<math.h>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORE(i,a,b) for(ll i = a; i <= b; i++)
#define getmax(a,b) a>b?a:b

int main()
{
    int n;
    ll sum,cnt;
    while(true)
    {
        cin>>n;
        if( n == -1 )
            break;
        int arr[n];
        sum = 0;
        cnt = 0;
        FOR(i,0,n)
        {
            cin>>arr[i];
            sum += arr[i];
        }
        if(sum%n != 0)
        {
            cout<<-1<<'\n';
        }
        else
        {
            int mean = sum/n;
            FOR(i,0,n)
            {
                if(arr[i]<mean)
                {
                    cnt = cnt + (mean - arr[i]);
                }
            }
            cout<<cnt<<'\n';
        }
    }
}
