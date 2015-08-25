#include <bits/stdc++.h>

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
#define gl(n) scanf("%lld",&n)

#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
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
        temp = arrg[i]; // assign temp the arr greater value
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

string divby2(string s) // The string passed is in correct order
{
    string res(s.length(),'0'); // Maximum value of quotient can be equal to the dividend length
    int temp,val,temp2;
    val = 0;
    forup(i,0,s.length())
    {
        temp2 = (val*10)+(s[i]-48);
        temp = temp2/2;
        if (temp == 0)
            val = s[i]-48;
        else if(temp2%2)
            val = temp2%2;
        else
            val = 0;
        res[i] = (temp+48);
    }
    return res; // The string is returned in the correct order
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

void eliminateZero(string &s) // Passed in correct order
{
    ll i;
    dforup(i,0,s.length()) //ignore untill the first non-zero element
    {
        if(s[i] != '0')
            break;
    }
    s = s.substr(i,s.length()-i);
    if(s.length() == 0)
        s = "0";
}

int main()
{
    string total,extra;
    int flag;
    forup(i,0,10)
    {
        total.clear();
        extra.clear();
        cin>>total;
        cin>>extra;
        reverse(total.begin(),total.end()); //could be added in the function
        reverse(extra.begin(),extra.end()); //could be added in the function
        string k,n,k2; // k2 is equal to 2*k
        k2 = add(total,extra); // k2 received is in reverse order
        reverse(k2.begin(),k2.end()); // make k2 in normal order
        eliminateZero(k2); // remove beginning zeros from k2 the divident
        //cout<<k2;pn;
        k = divby2(k2); // return is in correct order
        eliminateZero(k); // remove beginning zeros from k the quotient
        //cout<<k;pn;
        reverse(k.begin(),k.end());
        n = sub(total,k);
        reverse(k.begin(),k.end()); // to put in correct order
        reverse(n.begin(),n.end()); // to put in correct order
        printWithoutZero(k);
        printWithoutZero(n);
    }
}
