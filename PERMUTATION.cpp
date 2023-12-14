
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

const string TEMPLATE = "PERMUTATION";
const int N = 1e5+5;

int n,a[N],sum=0;
int ans[N];
ii p[N];
vector<ii> v[N];

signed main()
{
    fast;
    freopen((TEMPLATE+".inp").c_str(),"r",stdin);
    freopen((TEMPLATE+".out").c_str(),"w",stdout);
    cin>>n; sum=n;
    FOR(i,1,n)
        cin>>a[i],p[i]={a[i],i};
    sort(p+1,p+n+1);
    int curr=1,mxcurr=-1;
    FOR(i,1,n)
    {
        curr=1;
        int pre=p[i].fi;
        //cout<<i<<" "<<pre<<'\n';
        int j=i;
        while (p[j].fi==pre)
        {
            //cout<<p[j].fi<<" "<<pre<<" "<<curr<<" "<<j;
            v[curr].pb(p[j]);
            curr++;
            j++;
            //cout<<" "<<j<<'\n';
        }
        mxcurr=max(mxcurr,curr-1);
        i=j-1;
    }
    bool check=1;
    FOR(i,1,mxcurr)
    {
        int curr=1;
        for (auto j:v[i])
        {
            if (j.fi!=curr)
                check=0;
            curr++;
        }
    }
    if (!check)
        cout<<-1;
    else
    {
        cout<<mxcurr<<'\n';
        FOR(i,1,mxcurr)
        {
            for (auto j:v[i])
                ans[j.se]=i;
        }
        FOR(i,1,n)
            cout<<ans[i]<<" ";
    }
    return 0;
}