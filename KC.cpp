
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

const string TEMPLATE = "KC";
const int N = 1e5+5;

int n,k;
int a[257][257][257];
int f[257][257][257];
pair<ii,int> p[N];

// int cal_sum(int x1,int y1,int z1,int x2,int y2,int z2)
// {
//     return f[x2][y2][z2] - f[x2][y2][z1-1];
// }

int cal_sum(int s1,int s2,int s3,int x1,int x2,int x3){
    if (s1>x1) swap(s1,x1);
    if (s2>x2) swap(s2,x2);
    if (s3>x3) swap(s3,x3);
    return f[x1][x2][x3]-f[s1-1][x2][x3]-f[x1][s2-1][x3]-f[x1][x2][s3-1]+f[s1-1][s2-1][x3]+f[x1][s2-1][s3-1]+f[s1-1][x2][s3-1]-f[s1-1][s2-1][s3-1];
}


signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    FOR(i,1,n)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x++; y++; z++;
        a[x][y][z]++;
        p[i]={{x,y},z};
    }
     for(int i = 1; i <= 256; ++i)
        for(int j = 1; j <= 256; ++j)
            for(int k = 1; k <= 256; ++k)
                f[i][j][k] = f[i-1][j][k] + f[i][j][k-1] + f[i][j-1][k] - f[i][j-1][k-1]
                    - f[i-1][j][k-1] - f[i-1][j-1][k] + f[i-1][j-1][k-1] + a[i][j][k];
    int ans=1e9;
    FOR(i,1,n)
    {
        int x=p[i].fi.fi;
        int y=p[i].fi.se;
        int z=p[i].se;
        int L=0,R=256-min(min(x,y),z),mid,d=1e9;
        while (L<=R)
        {
            mid=L+R>>1;
            int x2=min(x+mid,256);
            int y2=min(y+mid,256);
            int z2=min(z+mid,256);
            if (cal_sum(x,y,z,x2,y2,z2) >= k)
                d=mid,R=mid-1;
            else L=mid+1;
        }
        ans=min(ans,d);
    }
    cout<<ans<<'\n';
    return 0;
}