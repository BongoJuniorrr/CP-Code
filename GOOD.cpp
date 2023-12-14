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

const string TEMPLATE = "GOOD";
const int N = 1e5+5;
const int delta = 3*N;

int n,a[5005],ans=0;
bool cnt[10*N],sum[10*N];

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    FOR(i,1,n)
    {
        FOR(j,1,i-1)
            if (sum[a[i]-a[j]+delta])
            {
                //cout<<a[i]<<" "<<a[j]<<" "<<a[i]-a[j]<<'\n';
                ans++;
                break;
            }
        FOR(j,1,i-1)
            sum[a[i]+a[j]+delta]=1;
        sum[a[i]+a[i]+delta]=1;
    }
    cout<<ans;
    return 0;
}