
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
#define iii pair<ii,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "milktea";
const int N = 1e5+5;

int n,m,k;
vector<ii> g[N];
int P[N],t[N];
ii dist[N];
ii dist2[N];

void dijkstra()
{
    FOR(i,1,n) dist[i]={1e18,0};
    priority_queue<iii,vector<iii>,greater<iii>> pq;
    FOR(i,1,k)
    {
        dist2[P[i]]={1e18,0};
        dist[P[i]]={0,P[i]};
        pq.push({dist[P[i]],P[i]});
    }
    while (!pq.empty())
    {
        int u=pq.top().se;
        int w=pq.top().fi.fi;
        pq.pop();
        if (w>dist[u].fi)
            continue;
        for (auto v:g[u])
        {
            int vv=v.fi;
            int ww=v.se;
            if (dist[vv].fi > dist[u].fi+ww)
            {
                dist[vv].fi=dist[u].fi+ww;
                dist[vv].se=dist[u].se;
                pq.push({dist[vv],vv});
            }
            if (dist[vv].fi!=1e18 && dist[vv].se!=dist[u].se)
            {
                if (dist2[dist[vv].se].fi > dist[vv].fi+dist[u].fi+ww)
                    dist2[dist[vv].se].fi=dist[vv].fi+dist[u].fi+ww,dist2[dist[vv].se].se=dist[u].se;//,cout<<u<<" "<<vv<<" "<<dist[u].se<<" "<<dist[vv].se<<" "<<dist[u].fi<<" "<<dist[vv].fi<<" "<<ww<<'\n';
                if (dist2[dist[u].se].fi > dist[vv].fi+dist[u].fi+ww)
                    dist2[dist[u].se].fi=dist[vv].fi+dist[u].fi+ww,dist2[dist[u].se].se=dist[vv].se;//,cout<<u<<" "<<vv<<" "<<dist[u].se<<" "<<dist[vv].se<<" "<<dist[u].fi<<" "<<dist[vv].fi<<" "<<ww<<'\n';
            }
        }
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m>>k;
    FOR(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    FOR(i,1,k) cin>>P[i]>>t[i];
    dijkstra();
    FOR(i,1,k)
        if (t[i])
            dist[P[i]]=dist2[P[i]];
    FOR(i,1,n)
        cout<<dist[i].fi<<" ";
    return 0;
}