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

const int N = 1e5+5;

int n,ans=0;
vector<int> g[N];
bool isVisit[N];

void DFS(int u,int pre)
{
	isVisit[u]=1;
	int child=0;
	for (auto v:g[u])
		if (!isVisit[v])
			child++,DFS(v,u);
	ans+=child;
	int k=0;
	while ((1<<k)-1<child)
		k++;
	ans+=k;
}

main()
{
	fast;
	// freopen((TEMPLATE+".inp").c_str(),"r",stdin);
	// freopen((TEMPLATE+".out").c_str(),"w",stdout);
	cin>>n;
	FOR(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	g[1].pb(1);
	DFS(1,1);
	cout<<ans;
}