
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

const string TEMPLATE = "name";

int n,m,s,t,ans=0;
int a[2005][2005];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void BFS()
{
    if (a[s][t]==1)
        return;
    queue<ii> Q;
    Q.push({s,t});
    a[s][t]=1; ans++;
    while (!Q.empty())
    {
        int x=Q.front().fi;
        int y=Q.front().se;
        Q.pop();
        FOR(k,0,3)
        {
            int u=x+dx[k];
            int v=y+dy[k];
            if (u<1 || u>n || v<1 || v>m || a[u][v]==1)
                continue;
            if (a[u][v]==0)
            {
                a[u][v]=1;
                ans++;
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
    cin>>n>>m>>s>>t;
    FOR(i,1,n) FOR(j,1,m) cin>>a[i][j];
    BFS();
    cout<<(ans==0 ? -1 : ans);
    return 0;
}