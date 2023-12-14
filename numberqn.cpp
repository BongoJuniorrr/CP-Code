
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

int n,MOD,q;
vector<ii> g[N];
string num[N];
int h[N],P[N][20];
pair<int,char> tr[N];
 
void DFS(int u,int pre)
{
    for (auto v:g[u])
    {
        int vv=v.fi;
        int ww=v.se;
        if (vv==pre)
            continue;
        tr[vv]={u,char(ww+48)};
        h[vv]=h[u]+1;
        P[vv][0]=u;
        DFS(vv,u);
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

void DFS2(int u,int pre)
{
    for (auto v:g[u])
    {
        int vv=v.fi;
        int ww=v.se;
        if (vv==pre)
            continue;
        num[vv]=num[u];
        num[vv].pb(char(ww+48));
        DFS2(vv,u);
    }
}

void sub1()
{
    cin>>q;
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        int lca=LCA(u,v);
        string s1="";
        string s2="";
        while (u!=lca)
        {
            s1+=tr[u].se;
            u=tr[u].fi;
        }
        while (v!=lca)
        {
            s2+=tr[v].se;
            v=tr[v].fi;
        }
        reverse(s2.begin(),s2.end());
        int ans=0;
        for (auto c:s1)
            ans*=10,ans+=c-'0',ans%=MOD;
        for (auto c:s2)
            ans*=10,ans+=c-'0',ans%=MOD;
        cout<<ans<<'\n';
    }
}

void sub2()
{
    cin>>q;
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>MOD;
    FOR(i,1,n-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    DFS(1,-1);
    DFS2(1,-1);
    pre_process();
    // if (n<=1000) sub1();
    // else sub2();
    sub2();
    return 0;
}