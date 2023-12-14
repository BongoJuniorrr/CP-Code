
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

const string TEMPLATE = "bl1";
const int N = 3e5+5;

int n,ans1=0,ans2=0;
ii point[N];
vector<ii> hull;

bool cmp(ii &A,ii &B, ii &C)
{
    return (B.fi-A.fi)*(C.se-A.se) - (B.se-A.se)*(C.fi-A.fi)>0;
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>point[i].fi>>point[i].se;
    sort(point+1,point+n+1);
    hull.pb(point[1]);
    FOR(i,2,n)
    {
        while (hull.size()>=2 && cmp(hull[hull.size()-2],hull.back(),point[i]))
            hull.pop_back();
        hull.pb(point[i]);
    }
    FOD(i,n-1,1)
    {
        while (hull.size()>=2 && cmp(hull[hull.size()-2],hull.back(),point[i]))
            hull.pop_back();
        hull.pb(point[i]);
    }
    //if (n>1) hull.pop_back();
    FOR(i,0,hull.size()-2)
    {
        ans1+=hull[i].fi*hull[i+1].se;
        ans2+=hull[i].se*hull[i+1].fi;
    }
    int res=ans2-ans1;
    cout<<res/2<<".";
    if (res&1) cout<<"5";
    else cout<<"0";
    return 0;
}