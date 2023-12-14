
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

const string TEMPLATE = "shortest";
const int N = 20000+5;

int n,m,u,v;
vector<ii> g[N];
int dist[N];

void dijkstra()
{
    FOR(i,1,n) dist[i]=1e18;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    dist[u]=0;
    pq.push({0,u});
    while (!pq.empty())
    {
        int x=pq.top().se;
        int w=pq.top().fi;
        pq.pop();
        if (x==v) return;
        if (w!=dist[x]) continue;
        for (auto i:g[x])
        {
            int vv=i.fi;
            int ww=i.se;
            if (dist[vv] > dist[x]+ww)
            {
                dist[vv]=dist[x]+ww;
                pq.push({dist[vv],vv});
            }
        }
    }
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m>>u>>v;
    FOR(i,1,m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});
    }
    dijkstra();
    cout<<(dist[v]==1e18 ? -1 : dist[v]);
    return 0;
}