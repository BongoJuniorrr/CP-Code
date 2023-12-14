
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

const string TEMPLATE = "evensub";
const int N = 1e5+5;
const int LG = 23;

int n,a[N],ans=0;
int ST[25][N][2];

void preprocess()
{
    for (int i = 1; i <= n; ++i) ST[0][i][0] = a[i],ST[0][i][1] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            ST[j][i][0] = min(ST[j - 1][i][0], ST[j - 1][i + (1 << (j - 1))][0]);
            ST[j][i][1] = max(ST[j - 1][i][1], ST[j - 1][i + (1 << (j - 1))][1]);
        }
}
int queryMin(int l, int r) 
{
    int k = __lg(r - l + 1);
    return min(ST[k][l][0], ST[k][r - (1 << k) + 1][0]);
}

int queryMax(int l, int r) 
{
    int k = __lg(r - l + 1);
    return max(ST[k][l][1], ST[k][r - (1 << k) + 1][1]);
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    preprocess();
    FOR(i,1,n)
    {
        FOR(j,i,n)
        {
            int mx=queryMax(i,j);
            int mi=queryMin(i,j);
            if ((mx-mi)%2==0) ans++,cout<<i<<" "<<j<<" "<<mi<<" "<<mx<<'\n';
        }
    }
    cout<<ans;
    return 0;
}