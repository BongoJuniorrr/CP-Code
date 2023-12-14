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

const string TEMPLATE = "alpha_country";
const int N = 1e5+5;
const int LG = log2(N)+1;

int n,a[N],sum[N],ans=0;
int st[LG+2][N];

void preprocess()
{
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int query(int l, int r) 
{
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".ans").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i];
    preprocess();
    FOR(i,1,n)
        FOR(j,i,n)
        {
            ans=max(ans,sum[j]-sum[i-1]-query(i,j));
        }
    cout<<ans;
    return 0;
}