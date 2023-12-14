
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

const string TEMPLATE = "name";
const int N = 1e5+5;

int n,q,a[N];
int BIT[N];

void update(int idx,int val)
{
    while (idx<=n)
    {
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int get(int idx)
{
    int sum=0;
    while (idx>0)
    {
        sum+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

int sum_range(int L,int R)
{
    return get(R)-get(L-1);
}

void upd_range(int L,int R,int val)
{
    update(L,val);
    update(R+1,-val);
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i],update(i,a[i]);
    while (q--)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int x,y,val;
            cin>>x>>y>>val;
            upd_range(x,y,val);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<sum_range(x,y)<<'\n';
        }
    }
    return 0;
}