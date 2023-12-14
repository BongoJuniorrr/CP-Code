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
const int N = 1e6+6;

int n,k,a[N],dp[N];
deque<int> dq;

main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    FOR(i,1,n)
        cin>>a[i];
    FOR(i,1,n)
    {
        while (!dq.empty() && a[i] <= a[dq.back()]) dq.pop_back();
        dq.pb(i);
        if (i>=k)
            dp[i]=dp[i-k]+a[dq.front()];
        while (!dq.empty() && dq.front()+k-1 <= i) dq.pop_front();
    }
    cout<<*max_element(dp+1,dp+n+1);
}