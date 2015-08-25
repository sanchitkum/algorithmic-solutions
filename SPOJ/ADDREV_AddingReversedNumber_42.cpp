using namespace std;

#include<iostream>

#define ll long long
#define FOR(i,a,b) for( ll i = a; i < b; i++ )

int main()
{
    ll n,x1,x2,res,t1,t2,t3;
    cin>>n;
    FOR(i,0,n)
    {
        t1 = t2 = t3 = res = 0;
        cin>>x1>>x2;
        while(x1>0)
        {
            //if(x1%10 == 0)
              //  continue;
            t1 = (t1*10) + (x1%10);;
            x1 /= 10;
        }
        while(x2>0)
        {
            //if(x2%10 == 0)
              //  continue;
            t2 = (t2*10) + (x2%10);;
            x2 /= 10;
        }
        t3 = t1 + t2;
        while(t3>0)
        {
            res = (res*10) + (t3%10);
            t3 /= 10;
        }
        cout<<res<<'\n';
    }
}
