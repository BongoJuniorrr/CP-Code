
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

const string TEMPLATE = "glass";
const int N=25;
const int MAXN = 2e6+6;

int n,k,res=1e18;
int C[N][N];
int dp[MAXN];
int cnt[N];

int phantich(int n)
{
    int sum=0;
    while (n)
        sum+=(n&1),n>>=1;
    return sum;
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    if(n==k)
    {
        cout<<0;
        return 0;
    }
    FOR(i,1,n)
        FOR(j,1,n) 
            cin>>C[i][j];
    for (int mask=(1<<n)-2;mask>=1;mask--)
    {
        dp[mask]=1e18;
        int size=0;
        FOR(i,0,n-1)
            if ((mask>>i)&1) 
            {
                size++;
                cnt[size]=i+1;
            }
        FOR(i,0,n-1)
        {
            if ((mask>>i)&1) 
                continue;
            int mx=1e18;
            FOR(j,1,size)
                mx=min(mx,C[i+1][cnt[j]]);
            dp[mask]=min(dp[mask],dp[mask+(1<<i)]+mx);
        }
        if (phantich(mask)==k) 
            res=min(res,dp[mask]);
    }
    cout<<res;
    return 0;
}