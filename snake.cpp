
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

const string TEMPLATE = "name";

int n,k,a[405],mx=0,s=0;
int dp[405][405];

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    FOR(i,1,n)
        cin>>a[i];
    FOR(i,1,n)
    {
        mx=max(mx,a[i]);
        s+=a[i];
        dp[i][0]=mx*i-s;
    }
    FOR(i,2,n)
    {
        FOR(kk,1,k)
        {
            dp[i][kk]=1e18;
            int mx=a[i],s=a[i];
            FOD(j,i-1,kk)
            {
                dp[i][kk]=min(dp[i][kk],dp[j][kk-1]+(i-j)*mx-s);
                mx=max(mx,a[j]);
                s+=a[j];
            }
        }
    }
    // FOR(i,1,n)
    // {
    //     FOR(j,0,k)
    //         cout<<dp[i][j]<<" ";
    //     cout<<'\n';
    // }
    cout<<dp[n][k];
    return 0;
}