
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

const string TEMPLATE = "scrat";
const int N = 1e5+5;

int n,m,a[N];
vector<int> g[N];
bool ans[N];
set<int> se[N];

void DFS(int u,int par)
{
    se[u].insert(a[u]);
    for (auto v:g[u])
    {
        if (v==par) continue;
        DFS(v,u);
        if (se[u].size() < se[v].size()) swap(se[u],se[v]);
        for (auto i:se[v]) se[u].insert(i);
    }
    if (se[u].size()==m) ans[u]=1;
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    DFS(1,-1);
    FOR(i,1,n) cout<<ans[i];
    return 0;
}