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

int n,m;
int w[M+1],l[M+1],r[M+1];
int dp[M+1][(1<<M)+5];

main()
{
	fast;
	// freopen((TEMPLATE+".inp").c_str(),"r",stdin);
	// freopen((TEMPLATE+".out").c_str(),"w",stdout);
	cin>>n>>m;
	FOR(i,0,m-1)
		cin>>w[i]>>l[i]>>r[i],dp[i][(1<<i)]=w[i];
	FOR(mask,0,(1<<m)-1)
	{
		vector<int> v;
		FOR(i,0,m-1)
			if ((mask>>i)&1)
				v.pb(i);
		for (auto i:v)
			for (auto j:v)
				if (i!=j)
					if (r[i] > r[j])
						dp[i][mask] = max(dp[i][mask],dp[j][mask^(1<<i)] + w[i]);
	}
	int ans=-1e18;
	FOR(i,0,m-1)
		ans=max(ans,dp[i][(1<<m)-1]);
	cout<<ans<<endl;
	// FOR(mask,0,(1<<m)-1)
	// {
	// 	cout<<mask<<endl;
	// 	FOR(i,0,m-1)
	// 		cout<<dp[i][mask]<<" ";
	// 	cout<<endl;
	// }
}