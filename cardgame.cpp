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
const string TEMPLATE = "TEST";

const int N = 1e6+6;

int n,d=0;
vector<int> v1;
set<int> v2;
bool kt[N];

main()
{
	fast;
	// freopen((TEMPLATE+".inp").c_str(),"r",stdin);
	// freopen((TEMPLATE+".out").c_str(),"w",stdout);
	cin>>n;
	int x;
	FOR(i,1,n)
		cin>>x,kt[x]=1,v1.pb(x);
	FOR(i,1,2*n)
		if (!kt[i])
			v2.insert(i),kt[i]=1;
	sort(v1.begin(),v1.begin()+n/2,greater<int>());
	sort(v1.begin()+n/2,v1.end());
	FOR(i,1,n/2)
	{
		int t=v1[i-1];
		auto idx = v2.end(); idx--;
		if (idx==v2.end())
			continue;
		if (*idx>t)
			d++,v2.erase(idx);
	}
	FOR(i,n/2+1,n)
	{
		int t=v1[i-1];
		auto idx = v2.lower_bound(t);
		if (idx==v2.begin())
			continue;
		idx--;
		if ((*idx)<t)
			d++,v2.erase(idx);
	}
	cout<<d;
}

/*

18  9  8  5  2 12  3 4 13 16
20 19 17 15 14 11 10 7  6  1

*/