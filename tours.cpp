
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
const int N = 2e5+5;

int n,m,a[N],ans;
bool b[N];
vector<ii> edge;
vector<int> query;
int par[N];
string res[N];

int find(int x)
{
    if (x==par[x])
        return x;
    return par[x]=find(par[x]);
}

void uni(int x,int y)
{
    x=find(x); y=find(y);
    if (x!=y)
    {
        par[y]=x;
        ans--;
    }
}

bool cmp(ii &X,ii &Y)
{
    int cx=max(a[X.fi],a[X.se]);
    int cy=max(a[Y.fi],a[Y.se]);
    if (cx!=cy)
        return cx>cy;
    else
        return min(a[X.fi],a[X.se]) > min(a[Y.fi],a[Y.se]);
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>m; ans=n;
    FOR(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        edge.pb({x,y});
    }
    FOR(i,1,n)
    {
        par[i]=i;
        int x;
        cin>>x;
        a[x]=i;
        query.pb(x);
    }
    sort(edge.begin(),edge.end(),cmp);
    reverse(query.begin(),query.end());
    int j=0;
    FOR(i,0,n-1)
    {
        int x=query[i];
        b[x]=1;
        while (j<m && edge[j].fi==x || edge[j].se==x)
        {
            if (!b[edge[j].fi] || !b[edge[j].se]) break;
            //cout<<x<<" "<<edge[j].fi<<" "<<edge[j].se<<'\n';
            uni(edge[j].fi,edge[j].se);
            j++;
        }
        //cout<<ans<<" ";
        if (ans<=(n-i))
            res[i+1]="YES";
        else res[i+1]="NO";
    }
    res[1]="YES";
    res[n]="YES";
    FOD(i,n,1)
        cout<<res[i]<<'\n';
    return 0;
}