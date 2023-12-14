
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

const string TEMPLATE = "thieve";
const int N = 1e6+6;

int n,k,ans=0;
ii a[N];
int b[N];
int c[N];
ii ST[4*N];

void update(int id,int L,int R,int x,int val)
{
    if (x<L || x>R)
        return;
    if (L==R)
    {
        ST[id]={val,L};
        return;
    }
    int mid=L+R>>1;
    update(2*id,L,mid,x,val);
    update(2*id+1,mid+1,R,x,val);
    if (ST[2*id].fi > ST[2*id+1].fi)
        ST[id]=ST[2*id];
    else ST[id]=ST[2*id+1]; 
}

ii get(int id,int L,int R,int u,int v)
{
    if (v<L || u>R)
        return {0,0};
    if (L>=u && R<=v)
        return ST[id];
    int mid=L+R>>1;
    ii get1 = get(2*id,L,mid,u,v);
    ii get2 = get(2*id+1,mid+1,R,u,v);
    if (get1.fi > get2.fi) return get1;
    return get2;
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>k;
    FOR(i,1,n)
        cin>>a[i].fi>>a[i].se;
    FOR(i,1,k)
        cin>>c[i];
    sort(a+1,a+n+1);
    FOR(i,1,n) b[i]=a[i].fi;
    b[n+1]=1e18;
    sort(c+1,c+k+1);
    FOR(i,1,n)
        update(1,1,n,i,a[i].se);
    FOR(i,1,k)
    {
        int idx=upper_bound(b+1,b+n+2,c[i])-b;
        idx--;
        if (idx==0)
            continue;
        ii p = get(1,1,n,1,idx);
        ans+=max((ll)0,p.fi);
        update(1,1,n,p.se,-1);
    }
    cout<<ans;
    return 0;
}