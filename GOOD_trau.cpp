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
const int delta = 1e9+9;

int n,a[5005],ans=0;
vector<int> v;

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".ans").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
        cin>>a[i];
    v.pb(delta);v.pb(delta);v.pb(delta);
    FOR(i,1,n)
    {
        bool ok=0;
        FOR(x,0,v.size()-3)
            FOR(y,0,v.size()-2)
                FOR(z,0,v.size()-1)
                    if (v[x]+v[y]+v[z]==a[i])
                        ok=1;
        ans+=ok;
        v.pb(a[i]);v.pb(a[i]);v.pb(a[i]);
    }
    cout<<ans;
    return 0;
}