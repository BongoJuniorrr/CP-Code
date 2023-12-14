
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

const string TEMPLATE = "capdoi";
const int N = 1e5+5;

int n,k,dp[N];
vector<int> g[N];
bool cnt[N];
int sz[N];
int ST[4*N];

void update(int id,int L,int R,int x,int val)
{
    if (x<L || x>R)
        return;
    if (L==R)
    {
        ST[id]+=val;
        return;
    }
    int mid=L+R>>1;
    update(2*id,L,mid,x,val);
    update(2*id+1,mid+1,R,x,val);
    ST[id]=ST[2*id]+ST[2*id+1];
}

int get(int id,int L,int R,int u,int v)
{
    if (v<L || u>R)
        return 0; 
    if (L>=u && R<=v)
        return ST[id];
    int mid=L+R>>1;
    int get1 = get(2*id,L,mid,u,v);
    int get2 = get(2*id+1,mid+1,R,u,v);
    return get1+get2;
}

void pre_DFS(int u)
{
    sz[u]=1;
    for (auto v:g[u])
    {
        pre_DFS(v);
        sz[u]+=sz[v];
    }
}

void DFS(int u)
{
    int bigChild = -1;
    for (auto v:g[u])
        if (bigChild==-1 || sz[v]>sz[bigChild])
            bigChild=v;
    for (auto v:g[u])
        if (v!=bigChild)
        {
            DFS(v);
            update(1,1,n,v,-1);
        }
    if (bigChild!=-1)
        DFS(bigChild);
    for (auto v:g[u])
        if (v!=bigChild)
            update(1,1,n,v,1);
    dp[u]=get(1,1,n,max(u-k,(int)1),min(u+k,n));
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        cnt[v]=1;
    }
    int root;
    FOR(i,1,n)
        if (!cnt[i])
            root=i;
    pre_DFS(root);
    DFS(root);
    int ans=0;
    FOR(i,1,n)
        ans+=dp[i];
    cout<<ans<<'\n';
    FOR(i,1,n)
        cout<<dp[i]<<" ";
    return 0;
}