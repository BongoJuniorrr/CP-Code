
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

int n,m;
int s,t,u,v;
vector<ii> g[N];
int dist[N][3];
int trace[N];

void dijkstra(int st,int en,int k)
{
    FOR(i,1,n) dist[i][k]=1e18;
    dist[st][k]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,st});
    while (!pq.empty())
    {
        int u=pq.top().se;
        int w=pq.top().fi;
        pq.pop();
        if (w > dist[u][k])
            continue;
        for (auto v:g[u])
        {
            int vv=v.fi;
            int ww=v.se;
            if (dist[vv][k] > dist[u][k]+ww)
            {
                dist[vv][k]=dist[u][k]+ww;
                trace[vv]=u;
                pq.push({dist[vv][k],vv});
            }
        }
    }
}

void path(int t)
{
    while (trace[t])
    {
        int s=trace[t];
        g[s].pb({t,0});
        g[t].pb({s,0});
        t=trace[t];
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m>>s>>t>>u>>v;
    FOR(i,1,m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});
        g[y].pb({x,w});
    }
    dijkstra(s,t,1);
    path(t);
    dijkstra(u,v,2);
    cout<<dist[v][2];
    return 0;
}