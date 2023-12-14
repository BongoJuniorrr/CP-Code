
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
  
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")

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

const string TEMPLATE = "trungvi";
const int N = 1e6+6;

int n,a[N],b,ans=0;
int L[N][3][3],R[N][3][3]; //L[0][0][0] -> L min, L[0][0][1] -> L max

signed main()
{
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>b;
    FOR(i,1,n) cin>>a[i];
    int idx=1; 
    while (a[idx]!=b) idx++;
    int cnt = 0;
    FOR(i,1,idx-1)
    {
        int pos = idx - i;
        cnt += (a[pos]>b) - (a[pos]<b);
        if (cnt>=0) L[i%2][cnt][1]++;
        else if (cnt<0) L[i%2][-cnt][0]++;
    }
    cnt = 0;
    for (int i=1;i<=n-idx;i++)
    {
        int pos = idx + i;
        cnt += (a[pos]>b) - (a[pos]<b);
        if (cnt>=0) R[i%2][cnt][1]++;
        else if (cnt<0) R[i%2][-cnt][0]++;
    }
    FOR(i,0,n)
    {
        ans+=L[0][i][1] * R[0][i][0];
        ans+=L[1][i][1] * R[1][i][0];
        ans+=L[0][i][0] * R[0][i][1];
        ans+=L[1][i][0] * R[1][i][1];
    }
    cout<<ans+L[0][0][1]+L[0][0][0]+R[0][0][1]+R[0][0][1]+L[0][0][1]*R[0][0][1]+L[0][0][0]*R[0][0][0]+1;
}