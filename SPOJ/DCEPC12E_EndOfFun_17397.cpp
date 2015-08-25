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
#define gl(n) cin>>n

#define pin(x) printf("%d\n",x)
#define pln(x) cout<<x<<"\n"
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define mp make_pair

ll arr1[101][101];
ll arr2[101][101];
//ll mat[101][101];
ll mat_sum;
int n;

void A(ll i, ll j, ll val)
{
    ll sum_old = 0;
    ll sum_new = 0;
    forup(k,0,n)
    {
        sum_old += arr1[i][j] * arr2[j][k];
        sum_new += val * arr2[j][k];
    }
    arr1[i][j] = val;
    mat_sum = mat_sum+sum_new-sum_old;
    pln(mat_sum);
}

void B(ll i, ll j, ll val)
{
    ll sum_old = 0;
    ll sum_new = 0;
    forup(k,0,n)
    {
        sum_old += arr1[k][i] * arr2[i][j];
        sum_new += arr1[k][i] * val;
    }
    arr2[i][j] = val;
    mat_sum = mat_sum+sum_new-sum_old;
    pln(mat_sum);
}

void multiply()
{
    mat_sum = 0;
    forup(i,0,n)
    {
        forup(j,0,n)
        {
            ll sum_mul = 0;
            forup(k,0,n)
            {
                sum_mul += arr1[i][k] * arr2[k][j];
            }
            //mat[i][j] = sum_mul;
            //mat_sum += mat[i][j];
            mat_sum += sum_mul;
        }
    }
}

int main()
{
    gi(n);
    forup(i,0,n) // Input for matrix A
    {
        forup(j,0,n)
        {
            cin>>arr1[i][j];
        }
    }

    forup(i,0,n) // Input for matrix B
    {
        forup(j,0,n)
        {
            cin>>arr2[i][j];
        }
    }

    multiply(); // Multiply the matrix and store the result

    ll q;
    gl(q);
    char ch;
    ll i,j,val;
    while(q--)
    {
        cin>>ch;
        cin>>i>>j>>val;
        if(ch == 'A')
            A(i,j,val);
        else if(ch == 'B')
            B(i,j,val);
    }
}
