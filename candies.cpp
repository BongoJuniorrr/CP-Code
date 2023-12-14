
//"----------------------------------------------------------------------------------------"
//"- Author: Hirobi aka BongoJuniorr"
//"- School: Le Quy Don High School for the Gifted"
//"- Date: 11/10/2023"
//"- Problem: CANDIES"
//"- File: CANDIES.cpp"
//"- I/O File: stdin/stdout"
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
const int N = 1e5+5;

struct node
{
    int mi,ma,lazy;
} ST[4*N];


int n,m,a[N];
vector<ii> idx;

void fix(int id,int L,int R)
{
    if (!ST[id].lazy) return;
    ST[id].mi+=ST[id].lazy;
    ST[id].ma+=ST[id].lazy;
    if (L!=R)
    {
        ST[2*id].lazy+=ST[id].lazy;
        ST[2*id+1].lazy+=ST[id].lazy;
    }
    ST[id].lazy=0;
}

void build(int id,int L,int R)
{
    if (L==R)
    {
        ST[id].mi=ST[id].ma=a[L];
        return;
    }
    int mid=L+R>>1;
    build(2*id,L,mid);
    build(2*id+1,mid+1,R);
    ST[id].ma=max(ST[2*id].ma,ST[2*id+1].ma);
    ST[id].mi=min(ST[2*id].mi,ST[2*id+1].mi);
}

void update(int id,int L,int R,int u,int v,int val)
{
    fix(id,L,R);
    if (v<L || u>R)
        return;
    if (L>=u && R<=v)
    {
        ST[id].lazy+=val;
        fix(id,L,R);
        return;
    }
    int mid=L+R>>1;
    update(2*id,L,mid,u,v,val);
    update(2*id+1,mid+1,R,u,v,val);
    ST[id].ma=max(ST[2*id].ma,ST[2*id+1].ma);
    ST[id].mi=min(ST[2*id].mi,ST[2*id+1].mi);
}

int get(int id,int L,int R,int u,int v,int x)
{
    fix(id,L,R);
    if (v<L || u>R || ST[id].ma<x)
        return 0;
    if (L>=u && R<=v && ST[id].mi>=x)
    {
        idx.pb({L,R});
        return R-L+1;
    }
    int mid=L+R>>1;
    int get1 = get(2*id,L,mid,u,v,x);
    int get2 = get(2*id+1,mid+1,R,u,v,x);
    return get1+get2;
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    build(1,1,n);
    cin>>m;
    while (m--)
    {
        int x;
        cin>>x;
        cout<<get(1,1,n,1,n,x)<<'\n';
        while (!idx.empty())
        {
            int L=idx.back().fi;
            int R=idx.back().se;
            idx.pop_back();
            // cout<<L<<" "<<R<<'\n';
            update(1,1,n,L,R,-1);
        }
    }
    return 0;
}