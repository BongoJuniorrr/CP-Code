
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

const string TEMPLATE = "rank";

int n,d,ans=0;
vector<ii> duong,am;

bool cmp(ii &X,ii &Y)
{
    int s1=X.fi+X.se;
    int s2=Y.fi+Y.se;
    if (s1==s2) return X.se>Y.se;
    return s1>s2;
}

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n>>d;
    FOR(i,1,n)
    {
        int a,b;
        cin>>a>>b;
        if (b>=0)
            duong.pb({a,b});
        else am.pb({a,b});
    }
    sort(duong.begin(),duong.end());
    for (auto i:duong)
    {
        if (i.fi<=d)
            d+=i.se,ans++;
    }
    int xet=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    sort(am.begin(),am.end(),cmp);
    for (auto i:am)
    {
        while (!pq.empty() && (d+i.se<0 || i.fi>d) && pq.top()<i.se) d-=pq.top(),pq.pop();
        if (i.fi<=d && d+i.se>=0)
            d+=i.se,pq.push(i.se);
        int temp = pq.size();
        xet=max(xet,temp);
    }
    cout<<ans+xet;
    return 0;
}