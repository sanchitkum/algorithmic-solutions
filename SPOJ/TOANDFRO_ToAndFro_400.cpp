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
    int inc,dec;
    string str;
    while(true)
    {
        cin>>n;
        if( n == 0 )
            break;
        str.erase(0,str.length());
        cin>>str;
        dec = (2*n)-1;
        inc = 1;
        FOR(i,0,n)
        {
            int j = i;
            int flag = 1;
            while( j < str.length())
            {
                cout<<str[j];
                if(flag == 1)
                    j = j + dec;
                else
                    j = j + inc;
                flag *= -1;
            }
            dec -= 2;
            inc +=2;
        }
        cout<<'\n';
    }
}
