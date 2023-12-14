
//"----------------------------------------------------------------------------------------"
//"- Author: Hirobi aka BongoJuniorr"
//"- School: Le Quy Don High School for the Gifted"
//"- Date: dd/mm/yyyy"
//"- Problem: "
//"- File: "
//"- I/O File: "
//"----------------------------------------------------------------------------------------"

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl endl(*)

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)

#define ull unsigned long long
#define ll long long
#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "samac";

int n,a[25],ans=0;
bool b[25];

void xuat()
{
	int cnt=0,sum=0;
	FOR(i,1,n)
	{
		if (b[i]) cnt++,sum+=a[i];
		if (sum<0)
			return;
	}
	if (sum>=0)
		ans=max(ans,cnt);
}

void DFS(int i)
{
	if (i>n)
	{
		xuat();
	}
	else
	{
		FOR(j,0,1)
		{
			b[i]=j;
			DFS(i+1);
		}
	}
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    DFS(1);
    cout<<ans;
    return 0;
}