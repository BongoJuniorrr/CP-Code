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

int n,a[N],c[N],ans=0;

main()
{
	fast;
	// freopen((TEMPLATE+".inp").c_str(),"r",stdin);
	// freopen((TEMPLATE+".out").c_str(),"w",stdout);
	cin>>n;
	FOR(i,1,n)
		cin>>c[i];
	int id,low=1e18,sum=0;
	FOR(i,1,n)
	{
		sum+=c[i]-1;
		if (sum<low)
		{
			low=sum;
			id=i;
		}
	}
	id++;
	if (id>n)
		id=1;
	// id++;
	// if (id>n)
	// 	id=1;
	FOR(i,1,n)
	{
		a[i]=c[id++];
		if (id>n)
			id=1;
	}
	queue<int> vt;
	FOR(i,3,n)
		vt.push(i);
	vt.push(1); vt.push(2);
	FOR(i,2,n)
	{
		int t=a[i];
		while (t--)
		{
			int idx=vt.front();
			vt.pop();
			ans+=(idx-i)*(idx-i);
			cout<<i<<" "<<t<<" "<<idx<<" "<<ans<<endl;
		}
	}
	cout<<ans;
}
