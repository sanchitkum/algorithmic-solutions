using namespace std;
 
#include<iostream>
 
#define ll long long
#define FOR(i,a,b) for( i = a; i < b; i++ )
 
int main()
{
    int t,n,i;
    cin>>t;
    FOR(i,0,t)
    {
        int m = 1; // Number of digits in arr
        int arr[200] = {1};
        int j;
        cin>>n;
        FOR(j,1,n+1)
        {
            int temp = 0;
            int k;
            FOR(k,0,m)
            {
                int x = arr[k]*j + temp;
                arr[k] = x%10;
                temp = x/10;
            }
            while(temp)
            {
                arr[k++] = temp%10;
                m++;
                temp = temp/10;
            }
        }
        for(j = m-1; j>=0 ; j--)
            cout<<arr[j];
        cout<<'\n';
    }
}