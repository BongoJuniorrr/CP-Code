
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

const string TEMPLATE = "QUALUUNIEM";
const int N = 1e5+5;

int n,W,ans=0;
ii a[N];

bool cmp(ii &X,ii &Y)
{
    double d1 = double(X.se)/double(X.fi);
    double d2 = double(Y.se)/double(Y.fi);
    return d1>d2;
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>W;
    FOR(i,1,n) cin>>a[i].fi>>a[i].se;
    sort(a+1,a+n+1,cmp);
    FOR(i,1,n)
    {
        if (a[i].fi<=W)
            W-=a[i].fi,ans+=a[i].se;
    }
    cout<<ans;
    return 0;
}