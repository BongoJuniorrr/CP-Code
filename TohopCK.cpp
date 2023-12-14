
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

const string TEMPLATE = "TohopCK";
const int N = 1e5+5;
const int MOD=1e9+7;

int n,k,a[N],ans=0;
int C[55][N];

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    FOR(i,0,n) C[0][i]=1;
    FOR(i,1,n)
        FOR(kk,1,k)
            C[kk][i]=C[kk][i-1]+C[kk-1][i-1],C[kk][i]%=MOD;
    FOR(i,k,n)
    {
        ans+=C[k-1][i-1]*a[i];
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}