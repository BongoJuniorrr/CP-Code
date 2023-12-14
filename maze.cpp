
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
//#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "name";

int n,m;
char a[1500][1500];
int dist[1500][1500],path[1500][1500];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sx,sy;
vector<ii> super_water;

void water_bfs()
{
    FOR(i,1,n) FOR(j,1,m) dist[i][j]=1e9;
    queue<ii> Q;
    for (auto i:super_water)
        Q.push(i),dist[i.fi][i.se]=0;
    while (!Q.empty())
    {
        int x=Q.front().fi;
        int y=Q.front().se;
        Q.pop();
        FOR(k,0,3)
        {
            int u=x+dx[k];
            int v=y+dy[k];
            if (u<1 || u>n || v<1 || v>m)
                continue;
            if (dist[u][v] > dist[x][y]+1)
            {
                dist[u][v]=dist[x][y]+1;
                Q.push({u,v});
            }
        }
    }
    dist[sx][sy]=0;
}

void BFS()
{
    FOR(i,1,n) FOR(j,1,m) path[i][j]=1e9;
    path[sx][sy]=0;
    queue<ii> Q;
    Q.push({sx,sy});
    while (!Q.empty())
    {
        int x=Q.front().fi;
        int y=Q.front().se;
        Q.pop();
        FOR(k,0,3)
        {
            int u=x+dx[k];
            int v=y+dy[k];
            if (u<1 || u>n || v<1 || v>m || a[u][v]=='S' || a[u][v]=='X')
                continue;
            if (path[u][v]>path[x][y]+1 && dist[u][v]>path[x][y]+1)
            {
                path[u][v]=path[x][y]+1;
                Q.push({u,v});
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
    FOR(i,1,n) 
        FOR(j,1,m)
        { 
            cin>>a[i][j];
            if (a[i][j]=='E') sx=i,sy=j;
            if (a[i][j]=='S') super_water.pb({i,j});
        }
    water_bfs();
    BFS();
    int ans=1e9;
    FOR(i,1,n) ans=min(ans,path[i][1]);
    FOR(i,1,n) ans=min(ans,path[i][m]);
    FOR(j,1,m) ans=min(ans,path[1][j]);
    FOR(j,1,m) ans=min(ans,path[n][j]);
    cout<<(ans==1e9 ? -1 : ans+1)<<'\n';
    // FOR(i,1,n)
    // {
    //     FOR(j,1,m)
    //         cout<<setw(3)<<(path[i][j]==1e18 ? -1 : path[i][j])<<" ";
    //     cout<<'\n';
    // }
    return 0;
}