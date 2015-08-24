using namespace std;

#include<iostream>

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; i++ )
#define FORE(i,a,b) for(ll i = a; i <= b; i++ )

int main()
{
    int n,min = 0,max = 0;
    cin>>n;
    if(n>=3)
    {
        int arr[n];
        FOR(i,0,n)
            cin>>arr[i];
        min = 2001;
        for(int i=1;i<n-1;i++)
        {
            max = 0;
            for(int j=1;j<i;j++)
            {
                if(arr[j] - arr[j-1] > max)
                    max = arr[j] - arr[j-1];
            }
            for(int j=i+1;j<n;j++)
            {
                if(j == i+1)
                {
                    if(arr[j] - arr[j-2] > max)
                        max = arr[j] - arr[j-2];
                }
                else
                {
                    if(arr[j] - arr[j-1] > max)
                        max = arr[j] - arr[j-1];
                }
            }
            if(max<min)
                min = max;
        }
        cout<<min;
    }
}
