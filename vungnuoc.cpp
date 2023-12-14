
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

const string TEMPLATE = "vungnuoc";

int n,m,ans=0;
bool a[1005][1005];
queue<ii> coord;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void BFS(int s,int t)
{
    queue<ii> Q;
    Q.push({s,t});
    a[s][t]=1;
    while (!Q.empty())
    {
        int x=Q.front().fi;
        int y=Q.front().se;
        Q.pop();
        FOR(k,0,3)
        {
            int u=x+dx[k];
            int v=y+dy[k];
            if (u<1 || u>n || v<1 || v>m || a[u][v])
                continue;
            if (!a[u][v])
            {
                a[u][v]=1;
                Q.push({u,v});
            }
        }
    }
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m;
    FOR(i,1,n)
        FOR(j,1,m)
        {
            cin>>a[i][j];
            if (!a[i][j])
                coord.push({i,j});
        }
    while (!coord.empty())
    {
        int x=coord.front().fi;
        int y=coord.front().se;
        coord.pop();
        if (a[x][y]) continue;
        ans++;
        BFS(x,y);
    }
    cout<<ans;
    return 0;
}