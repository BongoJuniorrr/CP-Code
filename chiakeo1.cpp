
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

const string TEMPLATE = "chiakeo1";

int n,a[105];
unordered_map<int,int> ma;
vector<int> v,b;
int ans[105];

void phantich(int n)
{
    int uoc=1;
    while (uoc<n)
    {
        ma[uoc]++;
        uoc=n/(n/uoc)+1;
    }
    ma[n+1]++;
}

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n)
        phantich(a[i]);
    for (auto i:ma)
        v.pb(i.fi);
    for (auto x:v)
    {
        FOR(i,1,n)
            b.pb(a[i]/x);
        sort(b.begin(),b.end());
        int d=1;
        // cout<<x<<": ";
        // for (auto i:b)
        //     cout<<i<<" ";
        //cout<<'\n';
        FOR(i,1,b.size()-1)
            if (b[i]!=b[i-1])
            {
                //cout<<d<<" ";
                if (d<=n)
                {
                    if (ans[d]==0) ans[d]=x;
                    ans[d]=min(ans[d],x);
                }
                d=1;
            }
            else
                d++;
        //cout<<d<<" ";
        if (d<=n)
        {
            if (ans[d]==0) ans[d]=x;
            ans[d]=min(ans[d],x);
        }
        b.clear();
        //cout<<'\n';
    }
    FOR(i,1,n)
        if (ans[i])
            cout<<ans[i]<<'\n';
        else cout<<-1<<'\n';
    //cout<<v.size()<<'\n';
    //cout<<clock()/double(1000);
    return 0;
}