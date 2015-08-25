using namespace std;
#include<iostream>
int main()
{
    int t,a;
    string four = "64",nine = "19",two = "6248",three = "1397",seven = "1793",eight = "6842";
    long long b;
    cin>>t;
    while(t--){
        cin>>a>>b; a%=10;
        if (a==0 && b==0) continue;
        else if (b==0) cout<<"1";
        else if(a==0 || a==1 || a==5 || a==6) cout<<a;
        else if(a==4) cout<<four[b%2];
        else if(a==9) cout<<nine[b%2];
        else if(a==2) cout<<two[b%4];
        else if(a==3) cout<<three[b%4];
        else if(a==7) cout<<seven[b%4];
        else if(a==8) cout<<eight[b%4];
        cout<<'\n';}
}
