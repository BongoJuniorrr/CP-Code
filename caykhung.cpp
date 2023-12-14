#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl '\n'
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
const string TEMPLATE = "name";

int n,m,ans=0;
int par[10004];
priority_queue<iii,vector<iii>,greater<iii>> pq;

int find(int x)
{
	if (x==par[x])
		return x;
	return par[x]=find(par[x]);
}

void uni(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x!=y)
		par[y]=x;
}

main()
{
	fast;
	// freopen((TEMPLATE+".inp").c_str(),"r",stdin);
	// freopen((TEMPLATE+".out").c_str(),"w",stdout);
	cin>>n>>m;
	FOR(i,1,m)
	{
		int x,y,w;
		cin>>x>>y>>w;
		pq.push({w,{x,y}});
	}
	FOR(i,1,n)
		par[i]=i;
	while (!pq.empty())
	{
		int w=pq.top().fi;
		int u=pq.top().se.fi;
		int v=pq.top().se.se;
		if (find(u)!=find(v))
		{
			cout<<u<<" "<<v<<endl;
			uni(u,v);
			ans+=w;
		}
		pq.pop();
	}
	cout<<ans;
}
