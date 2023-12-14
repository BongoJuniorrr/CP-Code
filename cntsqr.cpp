
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
//#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "name";

int n,m,a[1505],b[1505],ans=0;
map<int,int> ma1,ma2;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m) cin>>b[i];
    FOR(i,1,n-1)
    {
        FOR(j,i+1,n)
            ma1[abs(a[i]-a[j])]++;
    }
    FOR(i,1,m-1)
    {
        FOR(j,i+1,m)
            ma2[abs(b[i]-b[j])]++;
    }
    for (auto i:ma1)
    {
        int v1=i.se;
        int v2=0;
        if (ma2[i.fi])
            v2=ma2[i.fi];
        ans+=v1*v2;
    }
    cout<<ans;
    return 0;
}