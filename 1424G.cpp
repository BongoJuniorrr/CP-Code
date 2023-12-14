
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

int n,ans=0,vt;
vector<ii> a;

signed main()
{
    fast;
    // freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    // freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        int L,R;
        cin>>L>>R;
        a.pb({L,R});
    }
    sort(a.begin(),a.end());
    vt=a[1].fi;
    priority_queue<int,vector<int>,greater<int>> pq;
    FOR(i,0,n-1)
    {
        while (!pq.empty() && pq.top()<=a[i].fi) pq.pop();
        pq.push(a[i].se);
        if (pq.size()>ans)
        {
            ans=pq.size();
            vt=a[i].fi;
        }
    }
    cout<<vt<<" "<<ans;
    return 0;
}