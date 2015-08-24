#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forup(i,a,b) for(ll i=a; i<b; i++)
#define fordn(i,a,b) for(ll i=a; i>=b; i--)
#define fore(i,a,b) for(ll i=a; i<=b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)

#define dforup(i,a,b) for(i=a; i<b; i++)
#define dfordn(i,a,b) for(i=a; i>=b; i--)
#define dfore(i,a,b) for(i=a; i<=b; i++)
#define drep(i,a) for(i=0; i<a; i++)

#define all(v) (v).begin(),(v).end() 
#define sz(v) int((v).size()) 
#define gi(n) scanf("%d",&n)
#define pin(x) printf("%d\n",x)
#define pn printf("\n")
#define ps printf(" ")

#define fs first
#define sc second
#define pb push_back
#define endl '\n'

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define repIt(v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define INPFILE freopen("input.in","r",stdin)
#define OUTPFILE freopen("out.txt","w",stdout)

int main()
{
	int n,val;
	gi(n);
	map<int,int> m_count;
	map<int,pii > m_pos;
	fore(i,1,n)
	{
		gi(val);
		if(!m_count[val])
			m_pos[val].fs = i; //Start
		m_pos[val].sc = i; //End
		m_count[val]++;
	}
	ll max_rep = 0;
	for( map<int,int>::iterator it = m_count.begin(); it != m_count.end(); ++it)
	{
		if( it->sc > max_rep)
			max_rep = it->sc;
	}
	pii ans_pair;
	int segment_size = 100100; // More than possible
	for( map<int,int>::iterator it = m_count.begin(); it != m_count.end(); ++it)
	{
		if(it->sc == max_rep)
		{
			if( (m_pos[it->fs].sc - m_pos[it->fs].fs) < segment_size )
			{
				ans_pair = m_pos[it->fs]; 
				segment_size = m_pos[it->fs].sc - m_pos[it->fs].fs; 
			}
		}		
	}
	cout<<ans_pair.fs<<" "<<ans_pair.sc;
}