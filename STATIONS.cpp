
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

const string TEMPLATE = "STATIONS";
const int N = 2e5+5;
const double eps = 1e-7;

int n;
double a[N];

bool check(double d)
{
    int cnt=1;
    int curr=1;
    FOR(i,2,n)
    {
        if (a[i]-a[curr]>2*d)
            cnt++,curr=i;
    }
    if (cnt<=3)
        return 1;
    return 0;
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    sort(a+1,a+n+1);
    double ans,mid,L=0,R=1e9;
    while (L<=R)
    {
        mid=(L+R)/double(2);
        if (check(mid))
        {
            ans=mid;
            R=mid-eps;
        }
        else L=mid+eps;
    }
    cout<<fixed<<setprecision(6)<<ans<<'\n';
    int curr=1;
    int cnt=0;
    a[n+1]=1e18;
    FOR(i,2,n+1)
    {
        if (a[i]-a[curr]>2*ans)
        {
            double coord=(a[i-1]+a[curr])/double(2);
            cnt++;
            cout<<fixed<<setprecision(6)<<coord<<" ";
            curr=i;
        }
    }
    if (cnt<3)
    {
        while (cnt<3)
            cout<<fixed<<setprecision(6)<<a[1]<<" ",cnt++;
    }
    return 0;
}