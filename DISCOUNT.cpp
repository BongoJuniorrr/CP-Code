
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

const string TEMPLATE = "DISCOUNT";
const int N = 1e6+6;

int n;
ii a[N];
int ST[4*N];

bool cmp(ii &X, ii &Y)
{
    if (X.se != Y.se)
        return X.se < Y.se;
    return X.fi<Y.fi;
}

void update(int id,int L,int R,int x,int val)
{
    if (x<L || x>R)
        return;
    if (L==R)
    {
        ST[id]=val;
        return;
    }
    int mid=L+R>>1;
    update(2*id,L,mid,x,val);
    update(2*id+1,mid+1,R,x,val);
    ST[id]=min(ST[2*id],ST[2*id+1]);
}

int get(int id,int L,int R,int u,int v)
{
    if (v<L || u>R)
        return 1e18;
    if (L>=u && R<=v)
        return ST[id];
    int mid=L+R>>1;
    int get1 = get(2*id,L,mid,u,v);
    int get2 = get(2*id+1,mid+1,R,u,v);
    return min(get1,get2);
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i].fi>>a[i].se;
    sort(a+1,a+n+1,cmp);
    FOR(i,1,n)
        update(1,1,n,i,a[i].fi);
    int sum=0;
    cout<<get(1,1,n,1,n)<<'\n';
    FOR(i,2,n)
    {
        update(1,1,n,i-1,1e18);
        sum+=a[i-1].se;
        //cout<<sum<<" "<<get(1,1,n,i,n)<<" ";
        cout<<sum+get(1,1,n,i,n)<<'\n';   
    }
    return 0;
}