
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

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")

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

const string TEMPLATE = "name";
const int N = 1e5+5;

int n,m,dist[N];
vector<ii> g[N];
vector<iii> vertices;
int sx,sy,fx,fy;

bool cmp1(iii &X,iii &Y)
{
    return X.fi.fi < Y.fi.fi;
}

bool cmp2(iii &X,iii &Y)
{
    return X.fi.se < Y.fi.se;
}

void dijkstra()
{
    FOR(i,1,m+2) dist[i]=1e18;
    dist[1]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,1});
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
            if (dist[vv] > dist[u]+ww)
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
    cin>>n>>m;
    cin>>sx>>sy>>fx>>fy;
    int cnt=2;
    FOR(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        vertices.pb({{x,y},cnt++});
    }
    sort(vertices.begin(),vertices.end(),cmp1);
    FOR(i,1,vertices.size()-1)
    {
        int u=vertices[i-1].se;
        int v=vertices[i].se;
        int x1=vertices[i-1].fi.fi;
        int x2=vertices[i].fi.fi;
        g[u].pb({v,x2-x1});
        g[v].pb({u,x2-x1});
    }
    sort(vertices.begin(),vertices.end(),cmp2);
    FOR(i,1,vertices.size()-1)
    {
        int u=vertices[i-1].se;
        int v=vertices[i].se;
        int x1=vertices[i-1].fi.se;
        int x2=vertices[i].fi.se;
        g[u].pb({v,x2-x1});
        g[v].pb({u,x2-x1});
    }
    for (auto i:vertices)
    {
        int u=1;
        int v=i.se;
        int x1=sx;
        int x2=i.fi.fi;
        int y1=sy;
        int y2=i.fi.se;
        g[u].pb({v,min(abs(x1-x2),abs(y1-y2))});
        g[v].pb({u,min(abs(x1-x2),abs(y1-y2))});
    }
    for (auto i:vertices)
    {
        int u=m+2;
        int v=i.se;
        int x1=fx;
        int x2=i.fi.fi;
        int y1=fy;
        int y2=i.fi.se;
        g[u].pb({v,abs(x1-x2)+abs(y1-y2)});
        g[v].pb({u,abs(x1-x2)+abs(y1-y2)});
    }
    g[1].pb({m+2,abs(sx-fx)+abs(sy-fy)});
    g[m+2].pb({1,abs(sx-fx)+abs(sy-fy)});
    dijkstra();
    cout<<dist[m+2];
    return 0;
}