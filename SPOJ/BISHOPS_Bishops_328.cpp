#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )

#define gi(n) scanf("%d",&n)
#define gl(n) cin>>n

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<'\n'
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

string add(string sg, string sm) //sg -> greater string // sm -> smaller string
{
    //The reverse string is passed into the function
    string res(sg.length()+1,'0'); // Maximum length can be one more than the largest string
    int temp,carry = 0;
    ll i;
    dforup(i,0,sm.length()) // Add untill the lower length of string
    {
        temp = sg[i] + sm[i] + carry - 96; // Add from both the strings
        if(temp > 9) // If temp value exceeds 9
            carry = temp/10; // carry = 1; then make carry 1
        else
            carry = 0;
        res[i] = (temp%10)+48; // Assign this character to result
    }
    dforup(i,sm.length(),sg.length()) //Add for all the remaining length of larger string
    {
        temp = sg[i] + carry - 48;
        if(temp > 9)
            carry = temp/10; // carry = 1;
        else
            carry = 0;
        res[i] = (temp%10)+48;
    }
    if(carry) // If in the end there exists a carry, then add it to the string
        res[i] = '1';
    return res; //Returns the string in reverse order
}

string sub(string sg, string sm) //sg -> greater string // sm -> smaller string
{
    //The reverse string is passed into the function
    string res(sg.length(),'0'); // Maximum lenght will be same as length of the greater string
    int temp,borrow = 0;
    int arrg[sg.length()]; // interger arrays to handle -1 case
    int arrm[sm.length()];
    int arrres[sg.length()];
    rep(sg.length()) // convert from string to interger array
        arrg[i] = sg[i]-48;
    rep(sm.length()) // convert from string to interger array
        arrm[i] = sm[i]-48;
    forup(i,0,sm.length()) //For the length of the smaller string keep subtracting
    {
        temp = arrg[i] - arrm[i]; // Subtract from larger string - smaller string
        if(temp < 0) // If the value is negative, then
        {
            temp = temp + 10; //increment it by 10
            arrg[i+1]--; //borrowing from the ahead value;
        }
        arrres[i] = temp;
    }
    forup(i,sm.length(),sg.length()) // For the remaining larger string
    {
        temp = arrg[i]; // assign temp from the arr greater string
        if(temp < 0) // if this value of temp is negative then
        {
            temp = temp+10; // increment by 10
            arrg[i+1]--; // borrow from the ahead value
        }
        arrres[i] = temp;
    }
    rep(sg.length()) // again put the integer array in the result string
        res[i] = arrres[i]+48;
    return res; //Returns the string in reverse order
}

void printWithoutZero(string s) // The string passed into the function is in correct direction
{
    ll i;
    dforup(i,0,s.length()) //ignore untill the first non-zero element
    {
        if(s[i] != '0')
            break;
    }
    s = s.substr(i,s.length()-i);
    if(s.length() == 0)
        cout<<"0";
    else
        cout<<s;
    pn;
}

int main()
{
    string s;
    while(cin>>s)
    {
        if(s == "0")
        {
            cout<<"0";pn;
            continue;
        }
        else if(s == "1")
        {
            cout<<"1";pn;
            continue;
        }
        string two = "2"; //n+(n-2);
        reverse(s.begin(),s.end()); //Reverse the string and then send to function
        string res = sub(s,two); //The function returns in reverse order
        res = add(s,res);
        reverse(res.begin(),res.end()); // To bring it to correct order
        printWithoutZero(res); //Print without leading zeroes
    }
}
