
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
const int N = 2e5+5;

int n,h,sumh=0;
int a[N],sum[N];
int st[21][N];

void preprocess()
{
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= 21; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int queryMax(int l, int r) 
{
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>h; sumh=(1+h)*h/2;
    FOR(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i],a[i]-=i;
    preprocess();
    int ans=1e18;
    FOR(i,h,n)
    {
        //cout<<i<<" "<<queryMax(i-h+1,i)<<" "<<sumh-sum[i]-sum[i-h]<<'\n';
        if (queryMax(i-h+1,i)+(i-h) <= 0)
            ans=min(ans,sumh-sum[i]+sum[i-h]);
    }
    cout<<(ans==1e18 ? -1 : ans);
    return 0;
}