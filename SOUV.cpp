
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

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimize("Ofast")

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
const int N = 1e4+5;

int n,m,k,P;
int dist[105][N];
int K[105],C[105];
vector<ii> g[N];
priority_queue<ii,vector<ii>,greater<ii>> pq;

void dijkstra(int s)
{
    FOR(i,1,n)
        dist[s][i]=1e9;
    dist[s][K[s]]=0;
    pq.push({0,K[s]});
    while (!pq.empty())
    {
        int u=pq.top().se;
        int w=pq.top().fi;
        pq.pop();
        if (w>dist[s][u])
            continue;
        for (auto v:g[u])
        {
            int vv=v.fi;
            int ww=v.se;
            if (dist[s][vv] > dist[s][u]+ww)
            {
                dist[s][vv]=dist[s][u]+ww;
                pq.push({dist[s][vv],vv});
            }
        }
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m>>k>>P;
    FOR(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    FOR(i,1,k)
        cin>>K[i]>>C[i],dijkstra(i);
    FOR(i,1,P)
    {
        int u,v;
        cin>>u>>v;
        int ans=1e9;
        FOR(kk,1,k)
        {
            if (dist[kk][u]!=1e9 && dist[kk][v]!=1e9)
                ans=min(ans,dist[kk][u]+dist[kk][v]+C[kk]);
        }
        cout<<(ans==1e9 ? -1 : ans)<<'\n';
    }
    return 0;
}