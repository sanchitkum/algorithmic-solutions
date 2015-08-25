//http://www.algorithmist.com/index.php/SPOJ_PALIN

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

//http://www.algorithmist.com/index.php/SPOJ_PALIN

/*
string result;

void addone(string s) // Recursive solution
{
    int temp,carry,i;
    i = carry = 0;
    s[0] = s[0] + 1;
    string res = s;
    drep(i,s.length())
    {
        temp = s[i] + carry - 48;
        if(temp > 9)
            carry = 1;
        else
            carry = 0;
        res[i] = (temp%10)+48;
    }
    if(carry)
        res.insert(i,"1",1); // '1' = carry+48
    string scopy(res); // Maintain a copy of the string to which one was added
    reverse(all(res));
    //cout<<"*"<<scopy;pn;
    //cout<<res<<"*";pn;
    if( scopy.compare(res) == 0)
    {
        result = res; //Assigns the global variable the result to store the answer
        return;
    }
    else
        addone(scopy);
}*/

/*
int main()
{
    ll t;
    gl(t);
    cin.ignore();
    string s;
    while(t--)
    {
        //result.clear();
        string res;
        //res.clear();
        getline(cin,s);
        reverse(all(s));
        res = s;
        while(true) // Iterative solution, same as recursive solution // Naive, keeps adding one and checks each time
        {
            int temp,carry,i;
            i = carry = 0;
            s[0] = s[0] + 1;
            drep(i,s.length())
            {
                temp = s[i] + carry - 48;
                if(temp > 9)
                    carry = 1;
                else
                    carry = 0;
                res[i] = (temp%10)+48;
            }
            if(carry)
                res.insert(i,"1",1); // '1' = carry+48
            string scopy(res); // Maintain a copy of the string to which one was added
            reverse(all(res)); // Reverse the res to obtain the correct order
            if( scopy.compare(res) == 0)
            {
                cout<<res;pn;  //Print the correct order of res
                break;
            }
            s = scopy; // Assign the new value of s to the previously added one value
        }
    }
}
*/

// returns true if v_mirror is greater than v, false otherwise
// note: we return false if they are equal because the palindrome we are seeking needs to be strictly greater
bool comp(vi v, vi v_mirror)
{
	if (v.size() != v_mirror.size())
		return v.size() < v_mirror.size();
	for (int i = 0; i < v.size(); i++)
		if (v[i] != v_mirror[i])
			return v[i] < v_mirror[i];
	return false;
}

/* // Recursive code for changing the v_mirror to next closest palindrome
void work(vi &v_mirror, int pos1, int pos2)
{
	if (pos1 < 0)
    {
		v_mirror[v_mirror.size()-1] = 1;
		v_mirror.insert(v_mirror.begin(), 1);
		return;
   	}
   	else if (v_mirror[pos1] < 9)
    {
      		v_mirror[pos1] = v_mirror[pos2] = v_mirror[pos1] + 1;
      		return;
   	}
   	else
    {
     		v_mirror[pos1] = v_mirror[pos2] = 0;
      		work(v_mirror, pos1-1, pos2+1);
      		return;
   	}
}
*/

vi v;
vi v_mirror;

int main()
{
    ll t;
    gl(t);
    cin.ignore();
    string s;
    while(t--)
    {
        getline(cin,s);
        v.clear();
        v_mirror.clear();
        forup(i,0,s.length())
            v.pb(s[i] - 48);

        ll i,j; // Creating the mirror vector
        dforup(i,0,v.size()/2)
            v_mirror.pb(v[i]);
        if(v.size()%2 == 1)
        {
            v_mirror.pb(v[i]);
            dforup(j,i+1,v.size())
                v_mirror.pb(v_mirror[--i]);
        }
        else
        {
            dforup(j,i,v.size())
                v_mirror.pb(v_mirror[--i]);
        }

        bool flag = comp(v,v_mirror);
        if(flag) //v_mirror is greater than v
        {
            rep(v_mirror.size())
                cout<<v_mirror[i];
            pn;
            continue;
        }

        /* // To use the recursive work function
        else //v_mirror is lesser than v
        {
            if(s.length()%2 == 0) // String length is even
                work(v_mirror,(v_mirror.size()/2)-1,v_mirror.size()/2);
            else // String length is odd
                work(v_mirror,v_mirror.size()/2,v_mirror.size()/2);
            rep(v_mirror.size())
                cout<<v_mirror[i];
            pn;
            continue;
        }
        */

        else
        {
            ll pos1,pos2;
            if(s.length()%2 == 0) // String length is even
            {
                pos1 = (v_mirror.size()/2)-1;
                pos2 = v_mirror.size()/2;
            }
            else
            {
                pos1 = v_mirror.size()/2;
                pos2 = v_mirror.size()/2;
            }
            while(true)
            {
                if (pos1 < 0)
                {
                    v_mirror[v_mirror.size()-1] = 1;
                    v_mirror.insert(v_mirror.begin(), 1);
                    break;
                }
                else if (v_mirror[pos1] < 9)
                {
                    v_mirror[pos1] = v_mirror[pos2] = v_mirror[pos1] + 1;
                    break;
                }
                else
                {
                    v_mirror[pos1] = v_mirror[pos2] = 0;
                    pos1 = pos1-1;
                    pos2 = pos2+1;
                    continue;
                }
            }
            rep(v_mirror.size())
                cout<<v_mirror[i];
            pn;
            continue;
        }
    }
}
