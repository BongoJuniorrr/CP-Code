
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

const string TEMPLATE = "ROUTE";
const int N = 5e5+5;

int n,m,b,r;
vector<int> food,military;
vector<int> g[N];
int dist[N];
bool isFood[N];

void BFS()
{
    deque<int> Q;
    FOR(i,1,n)
        dist[i]=1e18;
    for (auto i:food)
    {
        dist[i]=0;
        Q.push_back(i);
    }
    while (!Q.empty())
    {
        int u=Q.front();
        Q.pop_front();
        for (auto v:g[u])
        {
            int w=1;
            if (isFood[u] && isFood[v])
                w=0;
            if (dist[v] > dist[u]+w)
            {
                dist[v]=dist[u]+w;
                if (w)
                    Q.pb(v);
                else Q.push_front(v);
            }
        }
    }
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m>>b>>r;
    FOR(i,1,b)
    {
        int x;
        cin>>x;
        food.pb(x);
        isFood[x]=1;
    }
    FOR(i,1,r)
    {
        int x;
        cin>>x;
        military.pb(x);
    }
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    BFS();
    for (auto i:military)
        cout<<dist[i]<<" ";
    return 0;
}