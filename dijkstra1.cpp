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

int T,n,m;
vector<ii> g[N];
int dist[N];

void dijkstra()
{
    FOR(i,1,n) dist[i]=1e18;
    dist[1]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({dist[1],1});
    while (!pq.empty())
    {
        int u=pq.top().se;
        int w=pq.top().fi;
        pq.pop();
        if (w!=dist[u])
            continue;
        for (auto v:g[u])
        {
            int vv=v.fi;
            int ww=v.se;
            if (dist[vv]>dist[u]+ww)
            {
                dist[vv]=dist[u]+ww;
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
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if (u>v) swap(u,v);
            g[u].pb({v,w});
        }
        dijkstra();
        cout<<(dist[n]==1e18 ? -1 : dist[n])<<'\n';
        FOR(i,1,n)
            g[i].clear();
    }
    return 0;
}
