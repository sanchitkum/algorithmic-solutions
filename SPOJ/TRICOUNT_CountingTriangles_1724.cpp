//http://math.stackexchange.com/questions/203873/how-many-triangles

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    long long n;
    while(t--)
    {
        cin>>n;
        long long res = n*(n+2)*((2*n)+1)/8;
        cout<<res<<endl;
    }
}
