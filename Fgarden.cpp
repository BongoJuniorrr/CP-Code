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

const string TEMPLATE = "Fgarden";
const int N = 1e6+6;

int n,t,a[N],res=0;
int st[21][N][2];

void preprocess()
{
    for (int i = 1; i <= n; ++i) st[0][i][0] = st[0][i][1] = a[i];
    for (int j = 1; j <= 20; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            st[j][i][0] = min(st[j - 1][i][0], st[j - 1][i + (1 << (j - 1))][0]);
            st[j][i][1] = max(st[j - 1][i][1], st[j - 1][i + (1 << (j - 1))][1]);
        }
}
int query(int l, int r) 
{
    if (l>r) return 1e18;
    int k = __lg(r - l + 1);
    int minx = min(st[k][l][0], st[k][r - (1 << k) + 1][0]);
    int maxx = max(st[k][l][1], st[k][r - (1 << k) + 1][1]);
    return maxx-minx;
}

signed main()
{
    fast;
    freopen("Fgarden.inp","r",stdin);
    freopen("Fgarden.out","w",stdout);
    cin>>n>>t;
    FOR(i,1,n)
        cin>>a[i];
    preprocess();
    int j=1,res=0;
    FOR(i,1,n)
    {
        while (query(i,j)<=t && j<=n)
            j++;
        res=max(res,j-i);
        j--;
        j=max(j,i+1);
    }
    cout<<res;
    return 0;
}