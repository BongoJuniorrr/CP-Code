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

int n,a[N];
int b[N];
int c[N];
bool kt[N];

main()
{
	fast;
	freopen((TEMPLATE+".inp").c_str(),"r",stdin);
	freopen((TEMPLATE+".ans").c_str(),"w",stdout);
	cin>>n;
	FOR(i,1,n)
		cin>>a[i],b[i]=i,kt[a[i]]=1;
	int idx=1;
	FOR(i,1,2*n)
		if (!kt[i])
			c[idx]=i,idx++;
	int maxd=-1e18;
	do
	{
		int currd=0;
		FOR(i,1,n/2)
			if (a[i] < c[b[i]])
				currd++;
		FOR(i,n/2+1,n)
			if (a[i] > c[b[i]])
				currd++;
		maxd=max(maxd,currd);
	} while (next_permutation(b+1,b+n+1));
	cout<<maxd;
}