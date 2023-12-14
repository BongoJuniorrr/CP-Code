
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
const int N = 1e6+6;

int n,q;
int a[N];
ii ST[4*N];

void build(int id,int L,int R)
{
    if (L==R)
    {
        ST[id]={a[L],L};
        return;
    }
    int mid=L+R>>1;
    build(2*id,L,mid);
    build(2*id+1,mid+1,R);
    if (ST[2*id].fi > ST[2*id+1].fi) ST[id]=ST[2*id];
    else ST[id]=ST[2*id+1];
}

ii get(int id,int L,int R,int u,int v)
{
    if (v<L || u>R)
        return {-1,-1};
    if (L>=u && R<=v)
        return ST[id];
    int mid=L+R>>1;
    ii get1 = get(2*id,L,mid,u,v);
    ii get2 = get(2*id+1,mid+1,R,u,v);
    if (get1.fi > get2.fi) return get1;
    else return get2;
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>q;
    FOR(i,1,n)
        cin>>a[i];
    build(1,1,n);
    while (q--)
    {
        int x;
        cin>>x;
        ii L=get(1,1,n,1,x-1);
        ii R=get(1,1,n,x+1,n);
        if (x==1) L={-1,-1};
        if (x==n) R={-1,-1};
        cout<<L.se<<" "<<R.se<<'\n';
    }
    return 0;
}