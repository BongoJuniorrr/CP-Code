
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
const int N = 1e5+5;

int n,q;
int F[N],h[N],P[N][25];
vector<ii> g[N];
int trace[N];

void DFS(int u,int pre)
{
    for (auto v:g[u])
    {
        int vv=v.fi;
        int ww=v.se;
        if (vv==pre)
            continue;
        F[vv]=F[u]+ww;
        h[vv]=h[u]+1;
        P[vv][0]=u;
        DFS(vv,u);
        trace[vv]=u;
    }
}

void pre_process()
{
    for (int i=1;(1<<i)<=n;i++)
        for (int j=1;j<=n;j++)
            P[j][i]=P[P[j][i-1]][i-1];
}

int LCA(int x,int y)
{
    if (h[x]<h[y]) swap(x,y);
    int p=log2(n);
    for (int z=p;z>=0;z--)
        if (h[x] - (1<<z) >= h[y])
            x=P[x][z];
    if (x==y)
        return x;
    for (int z=p;z>=0;z--)
        if (P[x][z]!=P[y][z])
        {
            x=P[x][z];
            y=P[y][z];
        }
    return P[x][0];
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>q;
    FOR(i,1,n-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    DFS(1,-1);
    pre_process();
    while (q--)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int u,v;
            cin>>u>>v;
            cout<<F[u]+F[v]-2*F[LCA(u,v)]<<'\n';
        }
        else
        {
            int u,v,k;
            cin>>u>>v>>k;
            int lca,d1,d2;
            lca=LCA(u,v);
            d1=h[u]-h[lca];
            d2=h[v]-h[lca];
            bool check=0;
            if (k>d1)
            {
                u=lca;
                k-=d1;
                check=1;
            }
            else
                v=lca,swap(u,v);
            int z=0;
            lca=LCA(u,v);
            d1=h[u]-h[lca];
            d2=h[v]-h[lca];
            int cnt=d1+d2;
            if (check)
                cnt-=k-1;
            else cnt=k-1;
            //cout<<u<<" "<<v<<" "<<cnt<<" "<<k<<'\n';
            while (cnt)
            {
                int z=log2(cnt);
                v=P[v][z];
                cnt-=(1<<z);
            }
            cout<<v<<'\n';
        }
    }
    return 0;
}