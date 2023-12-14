
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
//#define int long long
#define ii pair<int,int>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "FARM";

int n,m,a[1005][1005],ans=0;
bool visit[1005][1005];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void BFS(int s,int t)
{
    int check=1;
    queue<ii> Q;
    Q.push({s,t});
    visit[s][t]=1;
    while (!Q.empty())
    {
        int x=Q.front().fi;
        int y=Q.front().se;
        Q.pop();
        FOR(k,0,7)
        {
            int u=x+dx[k];
            int v=y+dy[k];
            if (u<1 || u>n || v<1 || v>m)
                continue;
            if (a[u][v] == a[x][y] && !visit[u][v]) {
				visit[u][v] = 1;
				Q.push({u,v});
			}
			if (a[u][v] > a[x][y]) check = 0;
        }
    }
    ans+=check;
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m;
    FOR(i,1,n) FOR(j,1,m) cin>>a[i][j];
    FOR(i,1,n)
        FOR(j,1,m)
        {
            if (!visit[i][j] && a[i][j])
            {
                BFS(i,j);
            }
        }
    cout<<ans;
    return 0;
}