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

ll cnt;

void merge(ll arr[], int p, int r, int q)
{
     int temp [q-p+1];
     int i,j,k;
     i=p;
     j=r+1;
     k=0;
     while(i<= r && j<=q)
     {
         if(arr[i]<=arr[j])
             temp[k++] = arr[i++];
         else
         {
             temp[k++] = arr[j++];
             cnt += (r-i+1);
         }
     }
     while(i<=r)
     {
         temp[k++] = arr[i++];
     }
     while(j<=q)
     {
         temp[k++] = arr[j++];
     }
     i=p;
     for(j=0;j<k;j++)
     {
         arr[i++] = temp[j];
     }
}

void mergeSort(ll arr[], int p, int q)
{
     int r;
     if(p<q)
     {
            r=(p+q)/2;
            mergeSort(arr,p,r);
            mergeSort(arr,r+1,q);
            merge(arr,p,r,q);
     }
}

int main()
{
    ll t;
    gl(t);
    while(t--)
    {
        pn;
        cnt = 0;
        ll n;
        gl(n);
        ll arr[n];
        rep(n)
            gl(arr[i]);
        mergeSort(arr,0,n-1);
        pln(cnt);
    }
}
