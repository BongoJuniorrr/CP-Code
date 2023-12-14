
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
#define iii pair<int,ii>

#define fi first
#define se second
#define pb push_back

const string TEMPLATE = "caykhung";
const int N = 1e6+6;

int n,m,par[N],ans=0;
vector<iii> edge;

int find(int x)
{
    if (x==par[x])
        return x;
    return par[x]=find(par[x]);
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m;
    FOR(i,1,n) par[i]=i;
    FOR(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.pb({w,{u,v}});
    }
    sort(edge.begin(),edge.end());
    return 0;
}