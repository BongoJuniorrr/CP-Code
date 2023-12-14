
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

const string TEMPLATE = "name";
const int N = 1e5+5;

int n,m,ans=0;
vector<int> g[N];
int deleted[N],num[N],low[N],timeDFS=0;
stack<int> st;

void DFS(int u)
{
    st.push(u);
    num[u]=low[u]=++timeDFS;
    for (auto v:g[u])
    {
        if (deleted[v]) continue;
        if (!num[v])
        {
            DFS(v);
            low[u]=min(low[u],low[v]);
        } else low[u]=min(low[u],num[v]);
    }
    if (low[u]==num[u])
    {
        int v;
        ans++;
        do
        {
            v=st.top();
            st.pop();
            deleted[v]=1;
        } while (v!=u && !st.empty());
        
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
    }
    FOR(i,1,n)  if (!num[i]) DFS(i);
    cout<<ans;
    return 0;
}