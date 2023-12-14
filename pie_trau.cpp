#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl '\n'
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
const string TEMPLATE = "name";

const int M = 20;

int n,m,ans=-1e18;
int w[M+1],l[M+1],r[M+1];
int a[M+1],b[55+1];

bool check(int l,int r)
{
	bool ok=false;
	FOR(i,l,r)
		if (b[i]==0)
			b[i]=-1,ok=true;
	return ok;
}

main()
{
	fast;
	// freopen((TEMPLATE+".inp").c_str(),"r",stdin);
	// freopen((TEMPLATE+".out").c_str(),"w",stdout);
	cin>>n>>m;
	FOR(i,1,m)
		cin>>w[i]>>l[i]>>r[i];
	FOR(i,1,m)
		a[i]=i;
	do
	{
		int currd=0;
		memset(b,0,sizeof(b));
		bool ok=true;
		FOR(i,1,m)
		{
			if (!check(l[a[i]],r[a[i]]));
			ok=false;
			if (!ok)
				break;
			currd+=w[a[i]];
		}
	} while (next_permutation(a+1,a+m+1));
}