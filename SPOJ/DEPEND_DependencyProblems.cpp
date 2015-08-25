#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) v.begin(), v.end()
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )

#define gi(n) scanf("%d",&n)
//#define gl(n) cin>>n
#define gl(n) scanf("%lld",&n)

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

#define matrix vector< vector<ll> >
#define repIt(v)  for(auto it = v.begin(); it != v.end(); ++it ) //C++11

#define INPFILE freopen("input.in","r",stdin)

/*
Logic:
Cannot apply topological sort, as topological sort is only for Directed ACYCLIC Graph
Here cycles exist! If there exists a cycle then we cannot install all such packages
Also only packages that have dependency list mentioned can be installed.
Some pacakages may be unavailable;
*/

map<string,ll> msl; // Maps each unique string(package) to a number;
bool node[10010] = {0}; // Keeps a track all the packages that exist; (that are available)
bool cycle[10010] = {0}; // Helps in finding if a cycle exists or not;
bool mark[10010] = {0}; // Explored nodes
ll counter = 0; // Count of all the packages wheather present or absent
set<ll> depen_list[10010]; // A Set so that only unique entries are present; Stores all files each package is dependent on;
stack<ll> installable; // All the installable packages will be mentioned here

bool dfs(ll root)
{
    bool possible = 1; // Checks wheather the current node(package) is possible
    mark[root] = 1; // The given node is visited
    cycle[root] = 1; // Represents that the current node is part of the cycle;

    if(!node[root]) // If the given package is unavailable
        return 0;

    repIt(depen_list[root])
    {
        if(!mark[*it])
            possible *= dfs(*it);
        if(cycle[*it]) // If you encounter the pacakage is dependent on a package that is a part of a cycle then
            possible = 0; // Make the current package as impossible as it a part of a cycle
    }

    cycle[root] = 0; // Make the cycle of this point as 0, as it has come out of recursion, i.e the cycle
    if(possible)
        installable.push(root);
    return possible;
}

ll mapping(string str)
{
    if(msl.count(str)) // If the given string(package) exists
        return msl[str]; // return its integer value
    else
    {
        msl[str] = ++counter; // Assign the new string(package) a new inter value;
        return msl[str]; // and return this integer value
    }
}

int main()
{
    //INPFILE;
    char node_string[10010];
    char dependency_string[10010];
    while(scanf("%s",node_string) != -1)
    {
        ll node_val = mapping(string(node_string)); // Map the string with its number
        node[node_val] = 1; // Make this given package available
        while(true)
        {
            scanf("%s",dependency_string);
            if(dependency_string[0] == '0')
                break;
            ll depen_val = mapping(string(dependency_string)); // Map the dependency string with its number
            depen_list[node_val].insert(depen_val); // Insert in the dependency list of node_val, the pacakges it is dependent on
        }
    }

    bool res[10010] = {0};

    fore(i,1,counter) // For each package mentioned in counter, check if it is possible to install or not
    {
        if(node[i]) // If the package exists then (check for cycles, if no cycle it can be installed)
        {
            memset(mark,0,sizeof(mark)); // Mark all visited nodes as unvisited
            while(!installable.empty())
                {installable.pop();}
            bool check = dfs(i); // Apply dfs on the given package; (check for cycles)
            while(check && !installable.empty())
            {
                res[installable.top()] = 1;
                installable.pop();
            }
        }
    }

    ll cnt = 0;
    fore(i,1,counter)
        cnt += res[i];
    cout<<cnt;
}
