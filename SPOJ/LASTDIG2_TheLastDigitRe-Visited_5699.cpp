#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    string four = "64",nine = "19",two = "6248",three = "1397",seven = "1793",eight = "6842";
    while(t--){
        string s; cin>>s;
        int a = s[s.length()-1] - 48;
        long long b; cin>>b;
        if (a==0 && b==0) cout<<"1";
        else if (b==0) cout<<"1";
        else if(a==0 || a==1 || a==5 || a==6) cout<<a;
        else if(a==4) cout<<four[b%2];
        else if(a==9) cout<<nine[b%2];
        else if(a==2) cout<<two[b%4];
        else if(a==3) cout<<three[b%4];
        else if(a==7) cout<<seven[b%4];
        else if(a==8) cout<<eight[b%4];
        cout<<'\n';
    }
}
