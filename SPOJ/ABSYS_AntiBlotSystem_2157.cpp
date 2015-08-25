using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>

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

/*
int main()
{
    int t,plus,equal,match;
    ll x,y,z;
    gi(t);
    cin.ignore();
    string str;
    while(t--)
    {
        pn;
        str.clear();
        getline(cin,str);
        plus = str.find('+');
        equal = str.find('=');
        match = str.find("machula");
        if(match < plus)
        {
            y = atoll( str.substr(plus+2,equal-plus-3).c_str() );
            z = atoll( str.substr(equal+2,str.length()-equal-2).c_str() );
            x = z - y;
        }
        else if ( match > plus && match < equal )
        {
            x = atoll( str.substr(0,plus-1).c_str() );
            z = atoll( str.substr(equal+2,str.length()-equal-2).c_str() );
            y = z - x;
        }
        else if (match > equal)
        {
            x = atoll( str.substr(0,plus-1).c_str() );
            y = atoll( str.substr(plus+2,equal-plus-3).c_str() );
            z = x + y;
        }
        if(plus && equal && plus<equal) // Just a check to ensure the correct order input.
            cout<<x<<" + "<<y<<" = "<<z;pn;
    }
}
*/

int conv(string s)
{
    int val = 0;
    FOR(i,0,s.length())
    {
        if( !isdigit(s[i]) )
            return -1;
        val = val*10 + (s[i] - '0');
    }
    return val;
}

int main()
{
    string s1,s2,s3,s4,s5;
    int t,v1,v2,v3;
    gi(t);
    while(t--)
    {
        cin>>s1>>s2>>s3>>s4>>s5;
        v1 = conv(s1);
        v2 = conv(s3);
        v3 = conv(s5);
        if(v1<0) v1 = v3 - v2; // v1 + v2 = v3
        if(v2<0) v2 = v3 - v1;
        if(v3<0) v3 = v1 + v2;
        cout<<v1<<" + "<<v2<<" = "<<v3<<endl;
    }
}
