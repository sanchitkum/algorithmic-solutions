using namespace std;

#include<iostream>

#define ll long long
#define FOR(i,a,b) for( i = a; i < b; i++ )

int main()
{
    int n,res=1,a,b;
    cin>>n;
    if(n >= 0 && n <= 99)
    {
        a=n%10;
        b=(n%100)/10;
        if(a==0)
            res = 2;
        else if(a==1)
            res = 7;
        else if(a==2)
            res = 2;
        else if(a==3)
            res = 3;
        else if(a==4)
            res = 3;
        else if(a==5)
            res = 4;
        else if(a==6)
            res = 2;
        else if(a==7)
            res = 5;
        else if(a==8)
            res = 1;
        else if(a==9)
            res = 2;
        if(b==0)
            res *= 2;
        else if(b==1)
            res *= 7;
        else if(b==2)
            res *= 2;
        else if(b==3)
            res *= 3;
        else if(b==4)
            res *= 3;
        else if(b==5)
            res *= 4;
        else if(b==6)
            res *= 2;
        else if(b==7)
            res *= 5;
        else if(b==8)
            res *= 1;
        else if(b==9)
            res *= 2;
        cout<<res;
    }
}
