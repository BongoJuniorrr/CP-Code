
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

const string TEMPLATE = "SEQUNISS";
const int N = 2e5+5;

int n,a[N];
ii p[N];
int ST[4*N];

void update(int id,int L,int R,int x,int val)
{
    if (x<L || x>R)
        return;
    if (L==R)
    {
        ST[id]+=val;
        return;
    }
    int mid=L+R>>1;
    update(2*id,L,mid,x,val);
    update(2*id+1,mid+1,R,x,val);
    ST[id]=max(ST[2*id],ST[2*id+1]);
}

int get(int id,int L,int R,int u,int v)
{
    if (v<L || u>R)
        return 0;
    if (L>=u && R<=v)
        return ST[id];
    int mid=L+R>>1;
    int get1 = get(2*id,L,mid,u,v);
    int get2 = get(2*id+1,mid+1,R,u,v);
    return max(get1,get2);
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i],p[i]={a[i],i};
    sort(p+1,p+n+1);
    int curr=0;
    int pre=-1;
    FOR(i,1,n)
    {
        if (p[i].fi!=pre)
        {
            pre=p[i].fi;
            a[p[i].se]=++curr;
        }
        else a[p[i].se]=curr;
    }
    FOR(i,1,n) update(1,1,n,a[i],1);
    if (get(1,1,n,1,n)<=1)
    {
        cout<<0;
        return 0;
    }
    int j=1,ans=1e9;
    FOR(i,1,n)
    {
        while (get(1,1,n,1,n)>1 && j<=n)
        {
            update(1,1,n,a[j],-1);
            j++;
        }
        //cout<<i<<" "<<j<<'\n';
        if (get(1,1,n,1,n)<=1)
            ans=min(ans,j-i);
        j--;
        j=max(j,i);
        update(1,1,n,a[i],1);
        update(1,1,n,a[j],1);
    }
    cout<<ans;
    return 0;
}