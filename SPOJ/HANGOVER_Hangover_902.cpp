using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

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
    float c,sum;
    int cnt;
    while(true)
    {
        scanf("%4f",&c);
        if(c == 0.00)
            break;
        sum = 0;
        cnt = 0;
        while(sum<c)
        {
            cnt++;
            sum = sum + (1.0/(cnt+1));
        }
        cout<<cnt<<" card(s)";pn;
    }
}
