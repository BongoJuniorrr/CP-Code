
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

const string TEMPLATE = "AIRPORT";
const int N = 1e6+6;

int n,m,a[N];

bool check(int k) 
{
    int cnt=0;
    FOR(i,1,n)
        cnt+=k/a[i];
    if (cnt>=m) return 1;
    return 0;
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m;
    FOR(i,1,n)  cin>>a[i];
    int L=0,R=1e18,mid,ans=0;
    while (L<=R)
    {
        mid=L+R>>1;
        if (check(mid))
        {
            ans=mid;
            R=mid-1;
        } else L=mid+1;
    }
    cout<<ans;
    return 0;
}