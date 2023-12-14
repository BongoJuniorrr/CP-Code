
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

const string TEMPLATE = "TREE";
const int N = 10000+5;

int n,k,dp[N],ans=0;
vector<int> g[N];
bool visited[N];

void DFS(int u,int pre)
{
    visited[u] = true;
    for (auto v:g[u])
    {
        if (v==pre) 
            continue;
        if (!visited[v])
            DFS(v,u);
    }
    for (auto v:g[u])
    {
        if (v==pre)
            continue;
        dp[u]+=dp[v];
    }
    if (dp[u]>=k)
        ans++,dp[u]=0;
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>k>>n;
    FOR(i,2,n)
    {
        int x;
        cin>>x;
        g[i].pb(x);
        g[x].pb(i);
    }
    FOR(i,1,n)
        dp[i]=1;
    DFS(1,-1);
    cout<<ans;
    return 0;
}