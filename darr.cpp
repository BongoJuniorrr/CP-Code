
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

const string TEMPLATE = "name";
const int N = 2e5+5;

int n,a[N],ans=0,maxx;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    maxx=a[1];
    FOR(i,1,n) maxx=max(maxx,a[i]);
    sort(a+1,a+n+1);
    FOR(i,1,n)
    {
        for (int k=a[i]*2;k<=maxx*2;k+=a[i])
        {
            int idx=lower_bound(a+1,a+n+1,k)-a;
            idx--;
            //cout<<a[i]<<" "<<a[idx]<<" "<<k<<'\n';
            if (a[idx]>k-a[i])
                ans=max(ans,a[idx]%a[i]);
        }
    }
    cout<<ans<<'\n';
    return 0;
}